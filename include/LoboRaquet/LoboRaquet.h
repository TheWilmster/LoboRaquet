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

extern TCPsocket LoboRaquet_NetClient_ConnectTCP(IPaddress *ip, const char *host, Uint16 port);

extern TCPsocket LoboRaquet_NetServer_CreateSocketTCP(IPaddress *ip, Uint16 port);

extern TCPsocket LoboRaquet_NetServer_AcceptSocketTCP(TCPsocket serverSock);

extern IPaddress LoboRaquet_Net_GetSocketAddress(TCPsocket sock);

extern void LoboRaquet_Net_CloseSocketTCP(TCPsocket sock);

#endif
