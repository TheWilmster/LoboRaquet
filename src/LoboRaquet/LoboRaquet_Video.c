#include "Raquet.h"

SDL_Texture * LoboRaquet_LoadIMG(char * filename) {
    SDL_Surface *temp_surf;
    SDL_Texture *tex;
    temp_surf = IMG_Load(Raquet_AbsoluteToAsset(filename)); // load the png onto a temporary surface
    tex = SDL_CreateTextureFromSurface(Raquet_Renderer, temp_surf); // create a texture from said surface
    SDL_FreeSurface(temp_surf); // free the mf from meory
    return tex;
}

void LoboRaquet_PlaceIMG(SDL_Texture * tex, int x, int y) {
    int width;
    int height;
    SDL_QueryTexture(tex, NULL, NULL, &width, &height);
    SDL_Rect dstrect = {
        x,
        y,
        width,
        height
    };
    SDL_RenderCopy(Raquet_Renderer, tex, NULL, & dstrect);
}

void LoboRaquet_PlaceIMG_ext(SDL_Texture * tex, int x, int y, int xsize, int ysize, double angle, Raquet_Point center, SDL_RendererFlip flip) {
    SDL_Rect dstrect = {
        x - center.x,
        y - center.y,
        xsize,
        ysize
    };
    SDL_RenderCopyEx(Raquet_Renderer, tex, NULL, & dstrect, angle, & center, flip);
}

SDL_Texture *LoboRaquet_GetStringTexture(TTF_Font *font, char *string, int r, int g, int b, int alpha, Uint32 wraplength) {
    SDL_Surface *temp_surf;
    SDL_Texture *tex;
    SDL_Color color={ r, g, b, alpha };
    temp_surf = TTF_RenderText_Blended_Wrapped(font, string, color, wraplength);
    tex = SDL_CreateTextureFromSurface(Raquet_Renderer, temp_surf);
    SDL_FreeSurface(temp_surf);

    return tex;
}

int LoboRaquet_GetTextWidth(TTF_Font *font, char *string) {
    SDL_Texture *tex = LoboRaquet_GetStringTexture(font, string, 255, 255, 255, 255, 2147483647);
    int width;
    SDL_QueryTexture(tex, NULL, NULL, &width, NULL);
    SDL_DestroyTexture(tex);
    printf("%s", string);
    printf(" %d\n", width);
    return abs(width);
}

void LoboRaquet_PlaceText(TTF_Font *font, char *string, int x, int y) {
    SDL_Texture *tex = LoboRaquet_GetStringTexture(font, string, 255, 255, 255, 255, 2147483647);
    int width;
    int height;
    SDL_QueryTexture(tex, NULL, NULL, &width, &height);
    SDL_Rect dstrect = {
        x,
        y,
        width,
        height
    };
    SDL_RenderCopy(Raquet_Renderer, tex, NULL, & dstrect);
    SDL_DestroyTexture(tex);
}

void LoboRaquet_PlaceText_ext(TTF_Font *font, char *string, int x, int y, int xscale, int yscale, SDL_Color color, Uint32 wrapLength) {
    SDL_Texture *tex = LoboRaquet_GetStringTexture(font, string, color.r, color.g, color.b, color.a, wrapLength);
    int width;
    int height;
    SDL_QueryTexture(tex, NULL, NULL, &width, &height);
    SDL_Rect dstrect = {
        x,
        y,
        width * xscale,
        height * yscale
    };
    SDL_RenderCopy(Raquet_Renderer, tex, NULL, & dstrect);
    SDL_DestroyTexture(tex);
}

TTF_Font *LoboRaquet_LoadFont(char *filename, int size) {
    return TTF_OpenFont(Raquet_AbsoluteToAsset(filename), size);
}