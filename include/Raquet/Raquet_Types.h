#ifndef RAQUET_TYPES_H
#define RAQUET_TYPES_H

/** @file */

#include "Raquet.h"

/** @brief The Camera structure used to control where actors are drawn on the screen */
typedef struct Raquet_Camera {
    float x;    /**< The x position of the Camera */
    float y;    /**< The y position of the Camera */
} Raquet_Camera;

/** @brief The camera used by all of the built-in Raquet functions */
extern Raquet_Camera Camera;

/** @brief Contains an x and y coordinate */
typedef SDL_Point Raquet_Point;

/** @brief The standard AABB collision structure */
typedef struct Raquet_BoundingBox {
    int x1;     /**< The first x position */
    int y1;     /**< The first y position */
    int x2;     /**< The second x position */
    int y2;     /**< The second y position */
}
Raquet_BoundingBox;

/** @brief The "objects" of Raquet. Can hold graphical and logical information */
typedef struct Raquet_Actor {
    Raquet_Point position;  /**< The position in virtual space */

    SDL_Texture * tex;         /**< The texture drawn onto the screen */
    Raquet_Point origin;    /**< Our graphic origin point in which we are rotated around */
    int width;              /**< How wide we are in pixels (Defaults to the width of the texture the actor is initialized with) */
    int height;             /**< How tall we are in pixels (Defaults to the height of the texture the actor is initialized with) */
    int angle;              /**< The angle of the object, rorated around its origin point */

    Raquet_BoundingBox bbox;    /**< The Raquet_BoundingBox used to check for collision */

    SDL_RendererFlip flip;      /**< How we should be flipped. Uses an SDL_RendererFlip value */

} Raquet_Actor;

#endif
