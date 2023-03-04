//
// Created by nicol on 04/03/2023.
//

#ifndef URANUS_PRIMITIVETYPE_HPP
#define URANUS_PRIMITIVETYPE_HPP

/**
 * @brief Primitive type that a vertex array can render
 */
enum PrimitiveType {
    POINTS, /**< List of individual points */
    LINES, /**< List of individual lines */
    LINESTRIP, /**< List of connected lines, a point uses the previous point to form a line */
    TRIANGLES, /**< List of individual triangles */
    TRIANGLESTRIP, /**< List of connected triangles, a point uses the two previous points to form a triangle */
    TRIANGLEFAN, /**< List of connected triangles, a point uses the common center and the previous point to form a triangle */
    QUADS /**< List of individual quads */
};

#endif //URANUS_PRIMITIVETYPE_HPP
