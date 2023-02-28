//
// Created by nicol on 23/01/2023.
//

#include "engine/Systems.hpp"

void engine::system::position()
{
    auto &r = engine::Manager::getRegistry();
    for (auto [idx, pos, vel] : View<component::position, component::velocity>(*r)) {
        pos.x += vel.x;
        pos.y += vel.y;
    }
}

void engine::system::draw()
{
    auto &window = engine::Manager::getWindow();
    auto &r = engine::Manager::getRegistry();
    for (auto [idx, pos, drawable] : View<component::position, component::drawable>(*r)) {
        drawable.shape->setPosition(pos.x, pos.y);
        drawable.shape->setFillColor(drawable.color);
        window->draw(*drawable.shape);
    }
    for (auto [idx, pos, sprite] : View<component::position, component::sprite>(*r)) {
        sprite.sprite->setPosition(pos.x, pos.y);
        window->draw(*sprite.sprite);
    }
}

void engine::system::input(engine::Event event)
{
    auto &r = engine::Manager::getRegistry();
    for (auto [idx, inputKeyboard] : View<component::inputKeyboard>(*r))
        inputKeyboard.callback(idx, event);
    for (auto [idx, inputMouse] : View<component::inputMouse>(*r))
        inputMouse.callback(idx, event);
}

bool engine::system::isColliding(const sf::FloatRect &obj1, const sf::FloatRect &obj2)
{
    return obj1.left < obj2.left + obj2.width && obj1.left + obj1.width > obj2.left && obj1.top < obj2.top + obj2.height &&
        obj1.top + obj1.height > obj2.top;
}

void engine::system::collision()
{
    auto &window = engine::Manager::getWindow();
    auto &r = engine::Manager::getRegistry();
    for (auto [entity1, pos1, collision1] : View<component::position, component::collisionable>(*r)) {
        //start debug
//        sf::Vector2f size(collision1.width, collision1.height);
//        sf::RectangleShape rect(size);
//        rect.setFillColor(sf::Color::Transparent);
//        rect.setOutlineColor(sf::Color::White);
//        rect.setOutlineThickness(1);
//        rect.setPosition(pos1.x + collision1.x, pos1.y + collision1.y);
//        window->draw(rect);
        //end debug
        for (auto [entity2, pos2, collision2] : View<component::position, component::collisionable>(*r)) {
            if (entity1 == entity2) continue;
            const sf::FloatRect obj1{collision1.x + pos1.x, collision1.y + pos1.y, collision1.width, collision1.height};
            const sf::FloatRect obj2{collision2.x + pos2.x, collision2.y + pos2.y, collision2.width, collision2.height};
            if (isColliding(obj1, obj2)) {
                collision1.callback(entity1, entity2);
            }
        }
    }
}

void engine::system::loop()
{
    auto &r = engine::Manager::getRegistry();
    for (auto [idx, loop] : View<component::loop>(*r))
        loop.update(idx);
}

sf::IntRect get_animation_rect(int frame, int h_frame, int v_frame, sf::Vector2u size)
{

    sf::Vector2i frameSize(static_cast<int>(size.x) / h_frame, static_cast<int>(size.y) / v_frame);

    sf::Vector2i start{0, 0};
    for (int i = 0; i < frame; i++) {
        start.x += frameSize.x;
        if (start.x >= size.x) {
            start.x = 0;
            start.y += frameSize.y;
        }
    }
    sf::IntRect rect{start.x, start.y, frameSize.x, frameSize.y};
    return rect;
}

void engine::system::addNewAnimation(size_t entity, const std::string &name, bool loop, float length)
{
    engine::Clock clock;
    std::vector<component::frameData> frameList;
    component::animationData animationData{name, loop, length, clock, false, frameList};
    auto &r = engine::Manager::getRegistry();
    auto &animation = r->getComponent<component::animation>(entity);
    animation->value().animations.push_back(animationData);
}

void engine::system::insertAnimationFrame(size_t entity, const std::string &name, float frameTime, int frame)
{
    auto &r = engine::Manager::getRegistry();
    auto &animation = r->getComponent<component::animation>(entity);
    component::frameData frameData{frameTime, frame};
    for (component::animationData &animationData: animation->value().animations) {
        if (animationData.name == name) {
            animationData.frames.push_back(frameData);
            break;
        }
    }
}

void engine::system::playAnimation(size_t entity, const std::string &name)
{
    auto &r = engine::Manager::getRegistry();
    auto &animation = r->getComponent<component::animation>(entity);

    for (component::animationData &animationData: animation->value().animations) {

        animationData.isPlaying = animationData.name == name;
//        std::cout << name << ", " << animationData.name << ", isPlaying: " << animationData.isPlaying << std::endl;
    }
}

void engine::system::stopAnimation(size_t entity)
{
    auto &r = engine::Manager::getRegistry();
    auto &animation = r->getComponent<component::animation>(entity);

    for (component::animationData &animationData: animation->value().animations) {
        animationData.isPlaying = false;
    }
}

void engine::system::animation()
{
    auto &r = engine::Manager::getRegistry();
    for (auto [idx, sprite, animation] : View<component::sprite, component::animation>(*r)) {
        for (component::animationData &animationData: animation.animations) {
            if (!animationData.isPlaying)
                continue;
            if (animationData.clock.getElapsedTime().asSeconds() >= animationData.length) {
                if (animationData.loop) {
                    animationData.clock.restart();
                }
                else
                    animationData.isPlaying = false;
            } else {
                for (component::frameData &frame: animationData.frames) {

                    if (animationData.clock.getElapsedTime().asSeconds() >= frame.frameTime) {
                        sf::IntRect rect = get_animation_rect(frame.frame,
                                                              animation.hFrame,
                                                              animation.vFrame,
                                                              sprite.sprite->getTexture()->getSize());
                        sprite.sprite->setTextureRect(rect);
                    }
                }
            }
        }
    }
}



void engine::system::gameLoop()
{
    auto &window = engine::Manager::getWindow();
    while (window->isOpen()) {
        engine::Event event;
        while (window->pollEvent(event)) {
            if (event.type == engine::Event::Closed)
                window->close();
            engine::system::input(event);
        }

        window->clear();

        engine::system::loop();
        engine::system::position();
        engine::system::collision();
        engine::system::animation();
        engine::system::draw();

        window->display();
    }
}

void engine::system::gameInit()
{
    auto &window = engine::Manager::getWindow();
    auto &r = engine::Manager::getRegistry();
    window->setFramerateLimit(60);

    r->registerComponent<component::position>(deletePosition);
    r->registerComponent<component::velocity>(deleteVelocity);
    r->registerComponent<component::drawable>(deleteDrawable);
    r->registerComponent<component::inputKeyboard>(deleteInputKeyboard);
    r->registerComponent<component::inputMouse>(deleteInputMouse);
    r->registerComponent<component::sprite>(deleteSpriteComponent);
    r->registerComponent<component::loop>(deleteLoopComponent);
    r->registerComponent<component::collisionable>(deleteCollisionable);
    r->registerComponent<component::animation>(deleteAnimationComponent);
}








