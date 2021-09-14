#pragma once

#include <conio.h>
#include <malloc.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
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

// limites del cuadro
#define LEFT_FRAME 15
#define RIGHT_FRAME 58
#define TOP_FRAME 5
#define BOTTOM_FRAME 14

// Limite de los movimiento
#define SECOND 1000
#define SPEED_X 26 // 20
#define SPEED_Y 10 // 6
#define SECOND_X SECOND / SPEED_X
#define SECOND_Y SECOND / SPEED_Y

typedef struct Snake {
    COORD coord;
    int orientation;

    struct Snake *tail;
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
