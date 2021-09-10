#pragma once

#include <malloc.h>
#include <stdio.h>
#include <windows.h>
// [0 ; 15]
enum Colors {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARKGREY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

enum Orientations { UP, RIGHT, DOWN, LEFT };

// ฅʕ·ᴥ·　ʔฅ
#define APPLE 149

// Teclas de las Flechas
#define KEY_UP 72
#define KEY_RIGHT 77
#define KEY_DOWN 80
#define KEY_LEFT 75

// #define EXCLAMATION_MARK 173
// #define QUESTION_MARK 168
// #define A_ACCENT 160
// #define E_ACCENT 130
// #define I_ACCENT 161
// #define O_ACCENT 162
// #define U_ACCENT 163
// #define ENIE 164

// limites del cuadro
#define LEFT_FRAME 13
#define RIGHT_FRAME 56
#define TOP_FRAME 5
#define BOTTOM_FRAME 24

// Limite de los movimiento
#define SECOND 1000
#define SPEED_X 15
#define SPEED_Y 5
#define SECOND_X SECOND / SPEED_X
#define SECOND_Y SECOND / SPEED_Y

typedef struct Snake {
    COORD coord;
    int orientation;
    struct Snake *next;
} Snake;

typedef struct Chronometer {
    unsigned short sec;
    unsigned short min;
    unsigned short hour;
} Chronometer;

void gameLoop();

void appleAppear(Snake *snake);
int verifyCoord(Snake *snake, const int x, const int y);

void verifyError(void *arg, const int line);

void gotoxy(int x, int y);

void setColor(int value);
