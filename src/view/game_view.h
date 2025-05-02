#ifndef SNAKE_GAME_GAME_VIEW_H
#define SNAKE_GAME_GAME_VIEW_H

#include <stdio.h>
#include "../model/game.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define GRID_SIZE 20

typedef struct GameView GameView;

extern GameView *create_game_view(const Game *game);
extern void release_game_view(GameView *gameView);

extern void draw_game(GameView *gameView);

extern void toggle_full_screen(GameView *gameView);

#endif
