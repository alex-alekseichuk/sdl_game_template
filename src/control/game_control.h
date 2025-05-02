#ifndef SNAKE_GAME_CONTROL_H
#define SNAKE_GAME_CONTROL_H

typedef enum {
    CONTROL_NONE = 0,
    CONTROL_QUIT,
    CONTROL_FULL_SCREEN,
    CONTROL_UP,
    CONTROL_DOWN,
    CONTROL_LEFT,
    CONTROL_RIGHT
} ControlEvent;

extern ControlEvent poll_event();

#endif
