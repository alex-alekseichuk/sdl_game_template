#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include "game.h"

void spawn_food(Game* game) {
    int valid;
    do {
        valid = 1;
        game->food.x = rand() % (game->width);
        game->food.y = rand() % (game->height);

        for (int i = 0; i < game->snake.length; i++) {
            if (game->food.x == game->snake.positions[i].x &&
                game->food.y == game->snake.positions[i].y) {
                valid = 0;
                break;
            }
        }
    } while (!valid);
}

Game *create_game(int width, int height) {
    srand(time(NULL));

    Game *game = (Game *)malloc(sizeof(Game));
    if (!game) {
        printf("Can't allocate memory for Game\n");
        return NULL;
    }

    game->width = width;
    game->height = height;
    game->snake = (Snake){
            {{width / 2,height / 2}},
            1,
            RIGHT
    };
    spawn_food(game);
    game->is_game_over = 0;

    return game;
}

void release_game(Game *game) {
    free(game);
}

void update_game(Game *game, uint32_t current_time) {
    static uint32_t last_update = 0;
    
    if (current_time - last_update >= MOVE_INTERVAL) {
        // save last position
        Position last_pos = game->snake.positions[game->snake.length - 1];

        // update snake positions
        for (int i = game->snake.length - 1; i > 0; i--) {
            game->snake.positions[i] = game->snake.positions[i - 1];
        }

        // move
        switch (game->snake.direction) {
            case UP:
                game->snake.positions[0].y--;
                break;
            case DOWN:
                game->snake.positions[0].y++;
                break;
            case LEFT:
                game->snake.positions[0].x--;
                break;
            case RIGHT:
                game->snake.positions[0].x++;
                break;
        }

        // check wall collision
        if (game->snake.positions[0].x < 0 ||
            game->snake.positions[0].x >= game->width ||
            game->snake.positions[0].y < 0 ||
            game->snake.positions[0].y >= game->height) {
            game->is_game_over = 1;
        }

        // check self collision
        for (int i = 1; i < game->snake.length; i++) {
            if (game->snake.positions[0].x == game->snake.positions[i].x &&
                game->snake.positions[0].y == game->snake.positions[i].y) {
                game->is_game_over = 1;
            }
        }

        // check food eating
        if (game->snake.positions[0].x == game->food.x && game->snake.positions[0].y == game->food.y) {
            if (game->snake.length < MAX_SNAKE_LENGTH) {
                game->snake.length++;
                game->snake.positions[game->snake.length - 1] = last_pos;
            }
            spawn_food(game);
        }

        last_update = current_time;
    }
}

void direct_snake(Game *game, Direction direction) {
    switch (direction) {
        case UP:
            if (game->snake.direction != DOWN) game->snake.direction = UP;
            break;
        case DOWN:
            if (game->snake.direction != UP) game->snake.direction = DOWN;
            break;
        case LEFT:
            if (game->snake.direction != RIGHT) game->snake.direction = LEFT;
            break;
        case RIGHT:
            if (game->snake.direction != LEFT) game->snake.direction = RIGHT;
            break;
    }
}

void game_over(Game *game) {
    game->is_game_over = 1;
}
