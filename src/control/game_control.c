#include <SDL3/SDL.h>
#include <stdio.h>
#include "game_control.h"

struct GameControl {
    const Game* game;
};

GameControl *create_game_control(const Game *game) {
    GameControl *gameControl = (GameControl *)malloc(sizeof(GameControl));
    if (!gameControl) {
        printf("Can't allocate memory for GameControl\n");
        return NULL;
    }

    *gameControl = (GameControl){
            .game = game,
    };

    return gameControl;
}

void release_game_control(GameControl *gameControl) {
    free(gameControl);
}

void process(GameControl *gameControl) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            game_over(gameControl->game);
        }
        else if (event.type == SDL_EVENT_KEY_DOWN) {
            switch (event.key.key) {
                case SDLK_UP:
                    direct_snake(gameControl->game, UP);
                    break;
                case SDLK_DOWN:
                    direct_snake(gameControl->game, DOWN);
                    break;
                case SDLK_LEFT:
                    direct_snake(gameControl->game, LEFT);
                    break;
                case SDLK_RIGHT:
                    direct_snake(gameControl->game, RIGHT);
                    break;
            }
        }
    }
}
