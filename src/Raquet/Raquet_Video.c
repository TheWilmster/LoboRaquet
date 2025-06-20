#include "Raquet.h"

/* Define the camera*/
Raquet_Camera Camera = {0, 0};

void Raquet_Clear(int red, int green, int blue, float alpha) {
    LoboRaquet_SetDrawColor(red, green, blue, alpha);
    SDL_RenderFillRect(Raquet_Renderer, NULL);
}

/* Draw a rectangle (x position, y position, width, height, color, alpha, fill) */
void LoboRaquet_DrawRectangle(int x1, int y1, int width, int height, int red, int green, int blue, float alpha, int fill) {
    SDL_Rect rect = {
        x1,
        y1,
        width,
        height
    };
    LoboRaquet_SetDrawColor(red, green, blue, alpha);

    switch (fill) {
    default:
        SDL_RenderDrawRect(Raquet_Renderer, & rect);
        break;

    case 1:
        SDL_RenderFillRect(Raquet_Renderer, & rect);
        break;
    }

}

void Raquet_DrawPoint(int x, int y, int red, int green, int blue, float alpha) {
    LoboRaquet_SetDrawColor(red, green, blue, alpha);
    SDL_RenderDrawPoint(Raquet_Renderer, x, y);
}

void Raquet_DrawLine(int x1, int y1, int x2, int y2, int red, int green, int blue, float alpha) {
    LoboRaquet_SetDrawColor(red, green, blue, alpha);
    SDL_RenderDrawLine(Raquet_Renderer, x1, y1, x2, y2);
}
