#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

typedef struct Controller Controller;

extern Controller *create_controller();
extern void release_controller(Controller *controller);
extern void run(Controller *controller);

#endif
