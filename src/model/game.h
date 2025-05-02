#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#define MAX_SNAKE_LENGTH 400
#define MOVE_INTERVAL 100

typedef struct {
    int x;
    int y;
} Position;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

typedef struct {
    Position positions[MAX_SNAKE_LENGTH];
    int length;
    Direction direction;
} Snake;

typedef struct {
    int width;
    int height;
    Snake snake;
    Position food;
    int is_game_over;
} Game;

extern Game *create_game(int width, int height);
extern void release_game(Game *game);
extern void update_game(Game *game, uint32_t current_time);

extern void direct_snake(Game *game, Direction direction);

#endif
