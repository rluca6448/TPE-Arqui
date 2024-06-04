#include "command.h"
#include "stdlib.h"
#include "eliminator.h"

#define WIDTH 80
#define HEIGHT 24
#define DELAY 9
#define MAX_TAIL_LENGTH (WIDTH * HEIGHT)

//void putSquare(int x, int y, const char *hex_color) {
//    // Implementation of this function should draw a square on the screen at position (x, y) with the color specified
//    printf("Drawing square at (%d, %d) with color %s\n", x, y, hex_color);
//}

typedef struct {
    int x, y;
} Segment;

typedef struct {
    int x, y, dir;
    Segment tail[MAX_TAIL_LENGTH];
    int tail_length;
} Player;

Player player;
int game_over = 0;

// Function prototypes for time functions
extern int ticks_elapsed();
extern void timer_handler();

void init() {
    player.x = WIDTH / 2;
    player.y = HEIGHT / 2;
    player.dir = 'd';  // Initialize direction to right
    player.tail_length = 0;
}

void end_game() {
    game_over = 1;
}

void add_tail_segment(int x, int y) {
    if (player.tail_length < MAX_TAIL_LENGTH) {
        player.tail[player.tail_length].x = x;
        player.tail[player.tail_length].y = y;
        player.tail_length++;
    }
}

void move_player() {
    int new_x = player.x;
    int new_y = player.y;

    switch (player.dir) {
        case 'w': new_y--; break;
        case 's': new_y++; break;
        case 'a': new_x--; break;
        case 'd': new_x++; break;
    }

    // Check for collisions with walls
    if (new_x < 0 || new_x >= WIDTH || new_y < 0 || new_y >= HEIGHT) {
        end_game();
    }

    // Check for collisions with tail
    for (int i = 0; i < player.tail_length; i++) {
        if (player.tail[i].x == new_x && player.tail[i].y == new_y) {
            end_game();
        }
    }

    // Move the tail
    if (player.tail_length > 0) {
        for (int i = player.tail_length - 1; i > 0; i--) {
            player.tail[i] = player.tail[i - 1];
        }
        player.tail[0].x = player.x;
        player.tail[0].y = player.y;
    }

    player.x = new_x;
    player.y = new_y;
    add_tail_segment(player.x, player.y);
}

void draw() {
    // Draw player
    putPixel("#FF0000", player.x, player.y);

    // Draw tail
    for (int i = 0; i < player.tail_length; i++) {
        //todo revisar coords
        putPixel("#00FF00", player.tail[i].x, player.tail[i].y);
    }
}

void handle_input() {
    // Simple input handling (replace with appropriate input mechanism)
    // This is just a placeholder to demonstrate the logic.
    char ch;
    char c = getKey();
        switch (ch) {
            case 'w':
            case 's':
            case 'a':
            case 'd':
                player.dir = ch;
                break;
            case 'q':
                end_game();
                break;
        }
}

void delay(int target_ticks) {
    int start_ticks = ticks_elapsed();
    while (ticks_elapsed() - start_ticks < target_ticks) {
        // Busy-wait loop
    }
}

void eliminator() {
    init();

    while (!game_over) {
        handle_input();
        move_player();
        draw();
        delay(DELAY); // delay for 0.5s
    }
}