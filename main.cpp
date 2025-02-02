#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>


const int SCREEN_W = 480;
const int SCREEN_H = 272;
const int PLAYER_W = 34;
const int PLAYER_H = 64;
const int GROUND_H = 50;
const int PLAYER_SPEED = 3;
const int JUMP_STRENGTH = -12;

struct Player {
    SDL_Rect rect;
    int velX, velY;
    bool onGround;
    int score;
};
struct Point {
    //sata andagii
    SDL_Rect rect;
    bool collected;
};

void handleEvents(SDL_Event &event, Player &player, bool &running, bool &inMenu) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        } else if (event.type == SDL_KEYDOWN) {
            if (inMenu) {
                if (event.key.keysym.sym == SDLK_RETURN) {
                    inMenu = false;
                }
            } else {
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        player.velX = -PLAYER_SPEED;
                        break;
                    case SDLK_RIGHT:
                        player.velX = PLAYER_SPEED;
                        break;
                    case SDLK_SPACE:
                        if (player.onGround) {
                            player.velY = JUMP_STRENGTH;
                            player.onGround = false;
                        }
                        break;
                }
            }
        } else if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT) {
                player.velX = 0;
            }
        }
    }
}
void update(Player &player,std::vector<Point> &points,Mix_Chunk *collectSound) {
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
    //Check for point collection
    for (auto &point : points) {
        if (!point.collected&&SDL_HasIntersection(&player.rect,&point.rect)) {
            point.collected = true;
            player.score++;
            Mix_PlayChannel(-1,collectSound,0);
        }
    }
}
int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);

    SDL_Window *window = SDL_CreateWindow("Simple Platformer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Load textures
    SDL_Surface *playerSurface = IMG_Load("ah.png");
    SDL_Texture *playerTexture = SDL_CreateTextureFromSurface(renderer, playerSurface);
    SDL_FreeSurface(playerSurface);

    SDL_Surface *groundSurface = IMG_Load("ground.png");
    SDL_Texture *groundTexture = SDL_CreateTextureFromSurface(renderer, groundSurface);
    SDL_FreeSurface(groundSurface);

    SDL_Surface *pointSurface = IMG_Load("point.png");
    SDL_Texture *pointTexture = SDL_CreateTextureFromSurface(renderer,groundSurface);
    SDL_FreeSurface(pointSurface);

    Mix_Chunk *collectSound = Mix_LoadWAV("collect.wav");
    // Initialize player
    Player player = {{100, SCREEN_H - GROUND_H - PLAYER_H, PLAYER_W, PLAYER_H}, 0, 0, false};

    SDL_Rect ground = {0, SCREEN_H - GROUND_H, SCREEN_W, GROUND_H};
    //Init Points
    std::vector<Point> points = {{ {200,SCREEN_H-GROUND_H -20,20,20}, false}};


    SDL_Event event;
    bool running = true;
    bool inMenu = true;

    while (running) {
        handleEvents(event, player, running,inMenu);
        if (!inMenu){
            update(player,points,collectSound);
        }



        // Render
        SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Light blue sky
        SDL_RenderClear(renderer);

        if (inMenu) {
            SDL_SetRenderDrawColor(renderer,0,0,0,255);
            SDL_Rect menuRect = {50,100,380,50};
            SDL_RenderFillRect(renderer,&menuRect);
        } else {
            SDL_RenderCopy(renderer, groundTexture, NULL, &ground);
            SDL_RenderCopy(renderer, playerTexture, NULL, &player.rect);
            for (const auto &point:points) {
                if (!point.collected) {
                    SDL_RenderCopy(renderer, pointTexture, NULL, &point.rect);
                }
            }
        }
        SDL_RenderPresent(renderer);
    }
    Mix_FreeChunk(collectSound);
    Mix_CloseAudio();

    SDL_DestroyTexture(playerTexture);
    SDL_DestroyTexture(groundTexture);
    SDL_DestroyTexture(pointTexture);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
