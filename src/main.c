#include "Raquet.h"

Raquet_Sound mu_test;
int playerx;
int playery;
TTF_Font *font;
float index;
int len;
char *text;

// I HATE actors.
//Raquet_Actor* act_placeface;

int main() {
    Raquet_Main();
    return 0;
}

// Runs once at the start of the program.
void createthedog() {
    mu_test = Raquet_LoadSound(Raquet_AbsoluteToAsset("mu_test.ogg"));
    Raquet_PlaySound(mu_test, -1);

    playerx = SCREEN_WIDTH / 2;
    playery = SCREEN_HEIGHT / 2;

    font = LoboRaquet_LoadFont("8bitoperator_jve.ttf", 16);
    index = 0.0;

    text = "LoboRaquet is my FAVORITE\nengine!";
    len = (int)strlen(text);
}

// Runs forever until the program is closed.
void runthedog() {
    Raquet_Clear(Raquet_GlobalPalette[0x18]); // Clears the screen to prevent stacking, specifically with the color green.

    int dirx = (Raquet_KeyCheck(SDL_SCANCODE_RIGHT) - Raquet_KeyCheck(SDL_SCANCODE_LEFT));
    int diry = (Raquet_KeyCheck(SDL_SCANCODE_DOWN) - Raquet_KeyCheck(SDL_SCANCODE_UP));

    if (Raquet_KeyCheck(SDL_SCANCODE_E)) {
        index = 0.0;
    }

    playerx += dirx;
    playery += diry;

    Raquet_Point test_point = { 25, 25 };

    SDL_Texture *png_test;
    png_test = LoboRaquet_LoadIMG("test_image.png");
    LoboRaquet_PlaceIMG_ext(png_test, playerx, playery, 50, 50, 0, test_point, SDL_FLIP_NONE);
    
    index += 0.5;
    index = fmin(index, len);
    int i = 0;
    int xstart = 25;
    int y1 = 25;
    int x1 = xstart;
    char newlineSymbol[] = "\n";

    for (i = 0; i < (int)index; i++) {
        char c = text[i];
        char str[] = "?";
        str[0] = c;
        
        if (strcmp(&str, &newlineSymbol) != 0) {
            LoboRaquet_PlaceText(font, str, x1, y1);
            x1 += 8;
        } else {
            x1 = xstart;
            y1 += 12;
        }
    }
}
// I HATE C99