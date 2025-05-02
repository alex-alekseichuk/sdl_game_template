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

    Controller *controller = (Controller *)malloc(sizeof(Controller));
    if (!controller) {
        free(game);
        free(gameView);
        printf("Can't allocate memory for Controller\n");
        return NULL;
    }

    *controller = (Controller){
        .game = game,
        .gameView = gameView,
    };

    return controller;
}

void release_controller(Controller *controller) {
    release_game_view(controller->gameView);
    release_game(controller->game);
    free(controller);
}

void run(Controller * controller) {
    bool is_running = true;

    while (is_running && !controller->game->is_game_over) {
        ControlEvent event;
        while (event = poll_event()) {
            switch (event) {
                case CONTROL_QUIT:
                    is_running = false;
                    break;
                case CONTROL_FULL_SCREEN:
                    toggle_full_screen(controller->gameView);
                    break;
                case CONTROL_UP:
                    direct_snake(controller->game, UP);
                    break;
                case CONTROL_DOWN:
                    direct_snake(controller->game, DOWN);
                    break;
                case CONTROL_LEFT:
                    direct_snake(controller->game, LEFT);
                    break;
                case CONTROL_RIGHT:
                    direct_snake(controller->game, RIGHT);
                    break;
            }
        }

        Uint32 current_time = SDL_GetTicks();
        update_game(controller->game, current_time);

        draw_game(controller->gameView);
    }

}
