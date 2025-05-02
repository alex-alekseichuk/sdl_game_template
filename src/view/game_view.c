#include <SDL3/SDL.h>
#include "../model/game.h"
#include "../view/game_view.h"

struct GameView {
    const Game *game;
    SDL_Window* window;
    SDL_Renderer *renderer;
};

GameView *create_game_view(const Game *game) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Window* window = SDL_CreateWindow("Snake Game",
                                          WINDOW_WIDTH, WINDOW_HEIGHT,
                                          SDL_WINDOW_RESIZABLE);
    if (!window) {
        SDL_Quit();
        printf("Window creation failed: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        printf("Renderer creation failed: %s\n", SDL_GetError());
        return NULL;
    }

    GameView *gameView = (GameView *)malloc(sizeof(GameView));
    if (!gameView) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        printf("Can't allocate memory for GameView\n");
        return NULL;
    }

    *gameView = (GameView){
        .game = game,
        .window = window,
        .renderer = renderer,
    };

    return gameView;
}

void release_game_view(GameView *gameView) {
    SDL_DestroyRenderer(gameView->renderer);
    SDL_DestroyWindow(gameView->window);
    SDL_Quit();
    free(gameView);
}

void draw_game(GameView *gameView) {
    const Game *game = gameView->game;

    SDL_SetRenderDrawColor(gameView->renderer, 0, 0, 0, 255);
    SDL_RenderClear(gameView->renderer);

    // snake
    SDL_SetRenderDrawColor(gameView->renderer, 0, 255, 0, 255);
    for (int i = 0; i < game->snake.length; i++) {
        SDL_FRect rect = {
                game->snake.positions[i].x * GRID_SIZE,
                game->snake.positions[i].y * GRID_SIZE,
                GRID_SIZE - 1,
                GRID_SIZE - 1
        };
        SDL_RenderFillRect(gameView->renderer, &rect);
    }

    // food
    SDL_SetRenderDrawColor(gameView->renderer, 255, 0, 0, 255);
    SDL_FRect food_rect = {
            game->food.x * GRID_SIZE,
            game->food.y * GRID_SIZE,
            GRID_SIZE - 1,
            GRID_SIZE - 1
    };
    SDL_RenderFillRect(gameView->renderer, &food_rect);

    SDL_RenderPresent(gameView->renderer);
}
