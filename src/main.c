#include "controller/controller.h"

int main(int argc, char* argv[]) {
    Controller *controller = create_controller();
    run(controller);
    release_controller(controller);

    return 0;
}
