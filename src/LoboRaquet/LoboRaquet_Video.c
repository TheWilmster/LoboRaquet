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

void LoboRaquet_PlaceText(TTF_Font *font, char *string, int x, int y) {
    SDL_Surface *temp_surf;
    SDL_Texture *tex;
    SDL_Color color={ 255, 255, 255, 255 };
    temp_surf = TTF_RenderUTF8_Solid(font, string, color);
    tex = SDL_CreateTextureFromSurface(Raquet_Renderer, temp_surf);

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
    SDL_FreeSurface(temp_surf);
    SDL_DestroyTexture(tex);
}

TTF_Font *LoboRaquet_LoadFont(char *filename, int size) {
    return TTF_OpenFont(Raquet_AbsoluteToAsset(filename), size);
}