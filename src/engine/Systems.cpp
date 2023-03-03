//
// Created by nicol on 23/01/2023.
//

#include "uranus/engine/Systems.hpp"
#include "uranus/engine/Rect.hpp"

void engine::system::position()
{
    auto &r = engine::Manager::getRegistry();
    for (auto [idx, pos, vel] : uranus::ecs::View<uranus::ecs::component::Position, uranus::ecs::component::Velocity>(*r)) {
        pos.x += vel.x;
        pos.y += vel.y;
    }
}

void engine::system::draw()
{
    auto &window = engine::Manager::getWindow();
    auto &r = engine::Manager::getRegistry();
    for (auto [idx, pos, drawable] : uranus::ecs::View<uranus::ecs::component::Position, uranus::ecs::component::Drawable>(*r)) {
        drawable.shape->setPosition(pos.x, pos.y);
        drawable.shape->setFillColor(drawable.color);
        window->draw(*drawable.shape);
    }
    for (auto [idx, pos, sprite] : uranus::ecs::View<uranus::ecs::component::Position, uranus::ecs::component::Sprite>(*r)) {
        sprite.sprite->setPosition(pos.x, pos.y);
        window->draw(*sprite.sprite);
    }
}

void engine::system::input(engine::Event event)
{
    auto &r = engine::Manager::getRegistry();
    for (auto [idx, inputKeyboard] : uranus::ecs::View<uranus::ecs::component::InputKeyboard>(*r))
        inputKeyboard.callback(idx, event);
    for (auto [idx, inputMouse] : uranus::ecs::View<uranus::ecs::component::InputMouse>(*r))
        inputMouse.callback(idx, event);
}

bool engine::system::isColliding(const sf::FloatRect &obj1, const sf::FloatRect &obj2)
{
    return obj1.left < obj2.left + obj2.width && obj1.left + obj1.width > obj2.left && obj1.top < obj2.top + obj2.height && obj1.top + obj1.height > obj2.top;
}

void engine::system::setLayer(size_t entity, const std::array<bool, LAYER_SIZE> &layer)
{
    auto &r = engine::Manager::getRegistry();
    auto &collision = r->getComponent<uranus::ecs::component::Collisionable>(entity);
    collision->value().layer = layer;
}

void engine::system::setMask(size_t entity, const std::array<bool, MASK_SIZE> &mask)
{
    auto &r = engine::Manager::getRegistry();
    auto &collision = r->getComponent<uranus::ecs::component::Collisionable>(entity);
    collision->value().mask = mask;
}

void engine::system::collision()
{
    auto &window = engine::Manager::getWindow();
    auto &r = engine::Manager::getRegistry();
    for (auto [entity1, pos1, collision1] : uranus::ecs::View<uranus::ecs::component::Position, uranus::ecs::component::Collisionable>(*r)) {
        // start debug
        /*sf::Vector2f size(collision1.width, collision1.height);
        sf::RectangleShape rect(size);
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineColor(sf::Color::White);
        rect.setOutlineThickness(1);
        rect.setPosition(pos1.x + collision1.x, pos1.y + collision1.y);
        window->draw(rect);*/
        // end debug

        for (auto [entity2, pos2, collision2] : uranus::ecs::View<uranus::ecs::component::Position, uranus::ecs::component::Collisionable>(*r)) {
            if (entity1 == entity2) continue;

            for (unsigned long i = 0; i < collision1.mask.size(); i++) {
                if (collision1.mask[i] && collision2.layer[i]) {
                    const sf::FloatRect obj1 {collision1.x + pos1.x, collision1.y + pos1.y, collision1.width, collision1.height};
                    const sf::FloatRect obj2 {collision2.x + pos2.x, collision2.y + pos2.y, collision2.width, collision2.height};
                    if (isColliding(obj1, obj2))
                        collision1.callback(entity1, entity2);
                    break;
                }
            }
        }
    }
}

void engine::system::loop()
{
    auto &r = engine::Manager::getRegistry();
    for (auto [idx, loop] : uranus::ecs::View<uranus::ecs::component::Loop>(*r))
        loop.update(idx);
}

sf::IntRect get_animation_rect(int frame, int h_frame, int v_frame, sf::Vector2u size)
{
    sf::Vector2i frameSize(static_cast<int>(size.x) / h_frame, static_cast<int>(size.y) / v_frame);

    sf::Vector2i start {0, 0};
    for (int i = 0; i < frame; i++) {
        start.x += frameSize.x;
        if (start.x >= size.x) {
            start.x = 0;
            start.y += frameSize.y;
        }
    }
    sf::IntRect rect {start.x, start.y, frameSize.x, frameSize.y};
    return rect;
}

void engine::system::addNewAnimation(size_t entity, const std::string &name, bool loop, float length)
{
    engine::Clock clock;
    std::vector<uranus::ecs::component::FrameData> frameList;
    uranus::ecs::component::AnimationData animationData {name, loop, length, clock, false, frameList};
    auto &r = engine::Manager::getRegistry();
    auto &animation = r->getComponent<uranus::ecs::component::Animation>(entity);
    animation->value().animations.push_back(animationData);
}

void engine::system::insertAnimationFrame(size_t entity, const std::string &name, float frameTime, int frame)
{
    auto &r = engine::Manager::getRegistry();
    auto &animation = r->getComponent<uranus::ecs::component::Animation>(entity);
    uranus::ecs::component::FrameData frameData {frameTime, frame};
    for (uranus::ecs::component::AnimationData &animationData : animation->value().animations) {
        if (animationData.name == name) {
            animationData.frames.push_back(frameData);
            break;
        }
    }
}

void engine::system::playAnimation(size_t entity, const std::string &name)
{
    auto &r = engine::Manager::getRegistry();
    auto &animation = r->getComponent<uranus::ecs::component::Animation>(entity);

    for (uranus::ecs::component::AnimationData &animationData : animation->value().animations) {
        if (animationData.name == name) {
            animationData.isPlaying = true;
            auto &sprite = r->getComponent<uranus::ecs::component::Sprite>(entity);
            sprite->value().sprite->setTextureRect(get_animation_rect(
                animationData.frames.data()->frame, animation->value().hFrame, animation->value().vFrame, sprite->value().sprite->getTexture()->getSize()));
        } else
            animationData.isPlaying = false;
    }
}

void engine::system::stopAnimation(size_t entity)
{
    auto &r = engine::Manager::getRegistry();
    auto &animation = r->getComponent<uranus::ecs::component::Animation>(entity);

    for (uranus::ecs::component::AnimationData &animationData : animation->value().animations) {
        animationData.isPlaying = false;
    }
}

void engine::system::animation()
{
    auto &r = engine::Manager::getRegistry();
    for (auto [idx, sprite, animation] : uranus::ecs::View<uranus::ecs::component::Sprite, uranus::ecs::component::Animation>(*r)) {
        for (uranus::ecs::component::AnimationData &animationData : animation.animations) {
            if (!animationData.isPlaying) continue;
            if (animationData.clock.getElapsedTime().asSeconds() >= animationData.length) {
                animation.callback(idx, animationData.name);

                if (animationData.loop) {
                    animationData.clock.restart();
                } else
                    animationData.isPlaying = false;
            } else {
                for (uranus::ecs::component::FrameData &frame : animationData.frames) {
                    if (animationData.clock.getElapsedTime().asSeconds() >= frame.frameTime) {
                        sf::IntRect rect = get_animation_rect(frame.frame, animation.hFrame, animation.vFrame, sprite.sprite->getTexture()->getSize());
                        sprite.sprite->setTextureRect(rect);
                    }
                }
            }
        }
    }
}

#include <spdlog/spdlog.h> // TODO: remove this

void engine::system::gameLoop()
{
    auto &window = engine::Manager::getWindow();
    auto &r = engine::Manager::getRegistry();
    sf::Clock deltaClock;
    while (window->isOpen()) {
        engine::Event event;
        while (window->pollEvent(event)) {
            if (event.type == engine::Event::Closed) window->close();
            engine::system::input(event);
        }
        auto time = deltaClock.restart();
        auto timeDeltaMs = static_cast<float>(static_cast<double>(time.asMicroseconds()) / 1000.0);
        auto fps = 1000.F / timeDeltaMs;
        spdlog::info("Alive entities: {}", r->entitiesAliveCount());
        spdlog::info("FPS: {:.1f} (Time delta: {:.3f} ms)", fps, timeDeltaMs);
        window->clear();

        engine::system::loop();
        engine::system::position();
        engine::system::collision();
        engine::system::animation();
        engine::system::draw();

        window->display();
    }
    auto &textureManager = engine::Manager::getTextureManager();
    textureManager.reset();
}

void engine::system::gameInit()
{
    auto &window = engine::Manager::getWindow();
    auto &r = engine::Manager::getRegistry();
    window->setFramerateLimit(60);

    r->registerComponent<uranus::ecs::component::Position>(deletePosition);
    r->registerComponent<uranus::ecs::component::Velocity>(deleteVelocity);
    r->registerComponent<uranus::ecs::component::Drawable>(deleteDrawable);
    r->registerComponent<uranus::ecs::component::InputKeyboard>(deleteInputKeyboard);
    r->registerComponent<uranus::ecs::component::InputMouse>(deleteInputMouse);
    r->registerComponent<uranus::ecs::component::Sprite>(deleteSpriteComponent);
    r->registerComponent<uranus::ecs::component::Loop>(deleteLoopComponent);
    r->registerComponent<uranus::ecs::component::Collisionable>(deleteCollisionable);
    r->registerComponent<uranus::ecs::component::Animation>(deleteAnimationComponent);
    r->registerComponent<uranus::ecs::component::Name>(deleteNameComponent);
}
