#include <SDL.h>
#include <SDL_image.h>
const int SCREEN_W = 480;
const int SCREEN_H = 272;
const int PLAYER_W = 34;
const int PLAYER_H = 64;
const int GROUND_H = 50;

struct Player {
    SDL_Rect rect;
    int velX, velY;
    bool onGround;
};
void handleEvents(SDL_Event &event, Player &player) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            exit(0);
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                    player.velX = -1;
                    break;
                case SDLK_RIGHT:
                    player.velX = 1;
                    break;
                case SDLK_SPACE:
                    if (player.onGround) {
                        player.velY = -15; // Jump strength
                        player.onGround = false;
                    }
                    break;
            }
        } else if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT) {
                player.velX = 0;
            }
        }
    }
}
void update(Player &player) {
    //Apply Gravity
    player.velY += 1;

    //update POS
    player.rect.x+=player.velX;
    player.rect.y+=player.velY;
    if (player.rect.y + PLAYER_H >= SCREEN_H - GROUND_H) {
        player.rect.y = SCREEN_H - GROUND_H - PLAYER_H;
        player.velY = 0;
        player.onGround = true;
    }
}
int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window *window = SDL_CreateWindow("Simple Platformer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Load textures
    SDL_Surface *playerSurface = IMG_Load("ah.png");
    SDL_Texture *playerTexture = SDL_CreateTextureFromSurface(renderer, playerSurface);
    SDL_FreeSurface(playerSurface);

    SDL_Surface *groundSurface = IMG_Load("ground.png");
    SDL_Texture *groundTexture = SDL_CreateTextureFromSurface(renderer, groundSurface);
    SDL_FreeSurface(groundSurface);

    // Initialize player
    Player player = {{100, SCREEN_H - GROUND_H - PLAYER_H, PLAYER_W, PLAYER_H}, 0, 0, false};

    SDL_Rect ground = {0, SCREEN_H - GROUND_H, SCREEN_W, GROUND_H};

    SDL_Event event;
    int running = 1;

    while (running) {
        handleEvents(event, player);
        update(player);

        // Render
        SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Light blue sky
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, groundTexture, NULL, &ground);
        SDL_RenderCopy(renderer, playerTexture, NULL, &player.rect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(playerTexture);
    SDL_DestroyTexture(groundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
