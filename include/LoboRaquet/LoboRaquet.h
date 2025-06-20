#ifndef LOBORAQUET_H
#define LOBORAQUET_H

/** @file */

/**
 * @brief Loads the texture of an image file.
 * @param filename The name of the image file to load.
 */
extern SDL_Texture *LoboRaquet_LoadIMG(char *filename);

/**
 * @brief dude im too fucking tired to tell you rn
 */
extern void LoboRaquet_PlaceIMG(SDL_Texture *tex, int x, int y);

/**
 * @brief dude im too fucking tired to tell you rn (but extended!)
 */
extern void LoboRaquet_PlaceIMG_ext(SDL_Texture *tex, int x, int y, int xsize, int ysize, double angle, Raquet_Point center, SDL_RendererFlip flip);

extern SDL_Texture *LoboRaquet_GetStringTexture(TTF_Font *font, char *string, int r, int g, int b, int alpha, Uint32 wraplength);

extern int LoboRaquet_GetTextWidth(TTF_Font *font, char *string);

extern int LoboRaquet_GetTextHeight(TTF_Font *font, char *string);

/**
 * @brief eventually im gonna have to make these actual descriptions
 */
extern void LoboRaquet_PlaceText(TTF_Font *font, char *string, int x, int y);

extern void LoboRaquet_PlaceText_ext(TTF_Font *font, char *string, int x, int y, int xscale, int yscale, SDL_Color color, Uint32 wrapLength);

TTF_Font *LoboRaquet_LoadFont(char *filename, int pointsize);

/**
 * @brief Wrapper for SDL's Render Set Draw Color that makes it slightly less complicated
 * @param red The color's red value ( 0 to 255 )
 * @param green The color's green value ( 0 to 255 )
 * @param blue The color's blue value ( 0 to 255 )
 * @param alpha The opacity of the color ( 0 to 1 )
 */
extern void LoboRaquet_SetDrawColor(int red, int green, int blue, float alpha);

#endif
