#include <SDL3/SDL.h>
#include <stdio.h>
#include <time.h>
#include "controller/controller.h"
#include "view/game_view.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(int argc, char* argv[]) {
    Controller *controller = create_controller();
    run(controller);
    release_controller(controller);

    return 0;
}
