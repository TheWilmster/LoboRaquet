#include "Raquet.h"

Raquet_Sound mu_test;
TTF_Font *font;
Raquet_Actor actor_test;
Raquet_Actor text_actor;
SDL_Texture *png_test;
SDL_Texture *text_texture;

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

    font = LoboRaquet_LoadFont("8bitoperator_jve.ttf", 16);

    png_test = LoboRaquet_LoadIMG("test_image.png");
    text_texture = LoboRaquet_GetStringTexture(font, "LoboRaquet is my FAVORITE engine!", 255, 255, 255, 255, SCREEN_WIDTH - 50);    

    Raquet_CreateActor(&actor_test, png_test);
    actor_test.position.x = SCREEN_WIDTH / 2;
    actor_test.position.y = SCREEN_HEIGHT / 2;
    actor_test.origin.x = 0;
    actor_test.origin.y = 0;
    actor_test.bbox.x1 = 28;
    actor_test.bbox.y1 = 32;
    actor_test.bbox.x2 = 66;
    actor_test.bbox.y2 = 96;

    Raquet_CreateActor(&text_actor, text_texture);
    text_actor.position.x = 20;
    text_actor.position.y = 20;
}

// Runs forever until the program is closed.
void runthedog() {
    Raquet_Clear(0, 150, 0, 1); // Clears the screen to prevent stacking, specifically with the color green.

    int dirx = (Raquet_KeyCheck(SDL_SCANCODE_RIGHT) - Raquet_KeyCheck(SDL_SCANCODE_LEFT));
    int diry = (Raquet_KeyCheck(SDL_SCANCODE_DOWN) - Raquet_KeyCheck(SDL_SCANCODE_UP));

    if (!Raquet_ActorColliding(actor_test.position.x + dirx, actor_test.position.y, &actor_test, &text_actor)) {
        actor_test.position.x += dirx;
    }

    if (!Raquet_ActorColliding(actor_test.position.x, actor_test.position.y + diry, &actor_test, &text_actor)) {
        actor_test.position.y += diry;
    }

    Raquet_DrawActor(&actor_test);
    
    Raquet_DrawActor(&text_actor);
}
// I HATE C99