#include <SDL3/SDL.h>
#include "../model/model.h"
#include "../view/game_view.h"

void draw_game(SDL_Renderer *renderer, const Game *game) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // snake
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (int i = 0; i < game->snake.length; i++) {
        SDL_FRect rect = {
                game->snake.positions[i].x * GRID_SIZE,
                game->snake.positions[i].y * GRID_SIZE,
                GRID_SIZE - 1,
                GRID_SIZE - 1
        };
        SDL_RenderFillRect(renderer, &rect);
    }

    // food
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_FRect food_rect = {
            game->food.x * GRID_SIZE,
            game->food.y * GRID_SIZE,
            GRID_SIZE - 1,
            GRID_SIZE - 1
    };
    SDL_RenderFillRect(renderer, &food_rect);
}
