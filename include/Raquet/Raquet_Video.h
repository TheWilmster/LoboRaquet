#ifndef RAQUET_VIDEO_H
#define RAQUET_VIDEO_H

/** @file */

/**
 * @brief Draws a single pixel onto the specified coordinates
 * @param x The screen X coordinate to draw the pixel to
 * @param y The screen Y coordinate to draw the pixel to
 * @param red The red color value
 * @param green the green color value
 * @param blue the blue color value
 * @param alpha The transpareny of the pixel
 */
void Raquet_DrawPoint(int x, int y, int red, int green, int blue, float alpha);

/**
 * @brief Draws a line onto the screen
 * @param x1 The first X coordinate
 * @param y1 The first Y coordinate
 * @param x2 The second X coordinate
 * @param y2 The second Y coordinate
 * @param red The red color value
 * @param green the green color value
 * @param blue the blue color value
 * @param alpha The transparency of the line
 */
void Raquet_DrawLine(int x1, int y1, int x2, int y2, int red, int green, int blue, float alpha);

#endif
