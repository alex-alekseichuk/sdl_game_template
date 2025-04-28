#include <SDL3/SDL.h>
#include <stdio.h>
#include <time.h>
#include "model/model.h"
#include "view/game_view.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(int argc, char* argv[]) {
    Game *game = create_game(WINDOW_WIDTH / GRID_SIZE, WINDOW_HEIGHT / GRID_SIZE);
    if (!game) {
        printf("Game initialization failed\n");
        return 1;
    }

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Snake Game",
                                          WINDOW_WIDTH, WINDOW_HEIGHT,
                                          SDL_WINDOW_RESIZABLE);
    if (!window) {
        printf("Window creation failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        return 1;
    }

    int game_over = 0;
    SDL_Event event;

    while (!game_over && !game->game_over) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                game_over = 1;
            }
            else if (event.type == SDL_EVENT_KEY_DOWN) {
                switch (event.key.key) {
                    case SDLK_UP:
                        direct_snake(game, UP);
                        break;
                    case SDLK_DOWN:
                        direct_snake(game, DOWN);
                        break;
                    case SDLK_LEFT:
                        direct_snake(game, LEFT);
                        break;
                    case SDLK_RIGHT:
                        direct_snake(game, RIGHT);
                        break;
                }
            }
        }

        Uint32 current_time = SDL_GetTicks();
        update_game(game, current_time);

        draw_game(renderer, game);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    release_game(game);

    return 0;
}
