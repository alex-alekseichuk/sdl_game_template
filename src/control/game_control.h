#ifndef SNAKE_GAME_CONTROL_H
#define SNAKE_GAME_CONTROL_H

#include "../model/game.h"

typedef struct GameControl GameControl;

extern GameControl *create_game_control(const Game *game);
extern void release_game_control(GameControl *gameControl);
extern void process(GameControl *gameControl);

#endif
