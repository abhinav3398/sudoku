#include <ctype.h>
#include <ncurses.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>


// macro for processing control characters
#define CTRL(x) ((x) & ~0140)

// size of each int (in bytes) in *.bin files
#define INTSIZE 4


// wrapper for our game's globals
typedef struct
{
    // the current level
    char *level;

    // the game's board
    int board[9][9];

    // locked cells in the board which are immutable (lookup - python tuples)
    bool locked[9][9];

    // the board's number
    int number;

    // the board's top-left coordinates
    int top, left;

    // the cursor's current location between (0,0) and (8,8)
    int y, x;

    // keep record of the time
    time_t current, start;
} Game;
extern Game g;

// prototypes used in our game
void draw_grid(void);
void draw_borders(void);
void draw_logo(void);
void draw_numbers(void);
void hide_banner(void);
bool load_board(void);
void handle_signal(int signum);
void log_move(int ch);
void redraw_all(void);
bool restart_game(void);
void show_banner(char *b);
void show_cursor(void);
void shutdown(void);
bool startup(void);
bool valid_move(int y, int x, int num);
bool won(void);
void hint(void);
bool pos_asPer_probability(bool numPlaces[9][9], __uint8_t num);
