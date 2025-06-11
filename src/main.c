#include "Raquet.h"

Raquet_Sound mu_test;
int playerx;
int playery;

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

    //act_placeface = Raquet_AllocateActor(); // Allocates memory for the actor.
}

// Runs forever until the program is closed.
void runthedog() {
    Raquet_Clear(Raquet_GlobalPalette[0x18]); // Clears the screen to prevent stacking, specifically with the color green.

    int dirx = (Raquet_KeyCheck(SDL_SCANCODE_RIGHT) - Raquet_KeyCheck(SDL_SCANCODE_LEFT));
    int diry = (Raquet_KeyCheck(SDL_SCANCODE_DOWN) - Raquet_KeyCheck(SDL_SCANCODE_UP));

    playerx += dirx;
    playery += diry;

    Raquet_Point test_point = { 25, 25 };

    SDL_Texture * png_test;
    png_test = LoboRaquet_LoadIMG("test_image.png");
    LoboRaquet_PlaceIMG_ext(png_test, playerx, playery, 50, 50, 0, test_point, SDL_FLIP_NONE);
}
