//
// Created by nicol on 02/03/2023.
//

#ifndef URANUS_CONVEX_HPP
#define URANUS_CONVEX_HPP

#include "Shape.hpp"

namespace uranus {
    /*
     * @brief Convex class
     */
    class Convex : public Shape {
    public:
        /**
         * @brief Default constructor
         */
         Convex(std::size_t pointCount = 0);

         /**
          * @brief Default destructor
          */
        ~Convex() = default;

        /**
         * @brief Set the number of points of the convex
         * @param pointCount Number of points of the convex
         */
        void setPointCount(std::size_t pointCount);

        /**
         * @brief Get the number of points of the convex
         * @return Number of points of the convex
         */
        std::size_t getPointCount() const;

        /**
         * @brief Set a point of the convex
         * @param index Index of the point
         * @param point Point of the convex
         */
        void setPoint(std::size_t index, const Vector2f &point);

        /**
         * @brief Get a point of the convex
         * @param index Index of the point
         * @return Point of the convex
         */
        Vector2f getPoint(std::size_t index) const;

    private:
        sf::ConvexShape _convex; /**< SFML convex */
    };
}


#endif //URANUS_CONVEX_HPP
