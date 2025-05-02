#include <SDL3/SDL.h>
#include "game_control.h"

ControlEvent poll_event() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            return CONTROL_QUIT;
        }
        else if (event.type == SDL_EVENT_KEY_DOWN) {
            switch (event.key.key) {
                case SDLK_Q:
                    return CONTROL_QUIT;
                case SDLK_F:
                    return CONTROL_FULL_SCREEN;
                case SDLK_UP:
                    return CONTROL_UP;
                case SDLK_DOWN:
                    return CONTROL_DOWN;
                case SDLK_LEFT:
                    return CONTROL_LEFT;
                case SDLK_RIGHT:
                    return CONTROL_RIGHT;
            }
        }
    }
}
