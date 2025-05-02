#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controller.h"
#include "../model/game.h"
#include "../view/game_view.h"
#include "../control/game_control.h"

struct Controller {
    Game *game;
    GameView *gameView;
    GameControl *gameControl;
};

Controller *create_controller() {
    Game *game = create_game(WINDOW_WIDTH / GRID_SIZE, WINDOW_HEIGHT / GRID_SIZE);
    if (!game) {
        printf("Game initialization failed\n");
        return NULL;
    }

    GameView *gameView = create_game_view(game);
    if (!gameView) {
        free(game);
        printf("GameView initialization failed\n");
        return NULL;
    }

    GameView *gameControl = create_game_control(game);
    if (!gameControl) {
        free(game);
        free(gameView);
        printf("GameControl initialization failed\n");
        return NULL;
    }

    Controller *controller = (Controller *)malloc(sizeof(Controller));
    if (!controller) {
        free(game);
        free(gameView);
        free(gameControl);
        printf("Can't allocate memory for Controller\n");
        return NULL;
    }

    *controller = (Controller){
        .game = game,
        .gameView = gameView,
        .gameControl = gameControl,
    };

    return controller;
}

void release_controller(Controller *controller) {
    release_game_view(controller->gameView);
    release_game(controller->game);
    free(controller);
}

void run(Controller * controller) {
    while (!controller->game->is_game_over) {
        process(controller->gameControl);

        Uint32 current_time = SDL_GetTicks();
        update_game(controller->game, current_time);

        draw_game(controller->gameView);
    }

}