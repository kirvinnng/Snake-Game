#include <conio.h>
#include <time.h>

#include "gui.h"
#include "snake.h"
#include "snake_function.h"

COORD apple;
int stayAlive = 1;
int score = 0;

int main() {
    SetConsoleTitle("Snake by kevin & matu <3");
    srand(time(NULL));
    // Tamaño  de la consola
    system("MODE 75, 30");

    // Cuadrante del juego
    printFrame(LEFT_FRAME - 1, TOP_FRAME - 1, RIGHT_FRAME + 1, BOTTOM_FRAME + 1);
    showInstructions();

    gameLoop();

    cleanLine(2);
    cleanLine(1);

    setColor(LIGHTCYAN);
    showScore(0);
    setColor(LIGHTMAGENTA);

    printFrame(LEFT_FRAME - 1, TOP_FRAME - 1, RIGHT_FRAME + 1, BOTTOM_FRAME + 1);

    showFinalScore(score);

    getchar();
    return 0;
}

void gameLoop() {
    Snake *snake = NULL;
    initSnake(&snake);
    appleAppear(snake);
    Chronometer timeinfo = {0};
    while (stayAlive) {
        stayAlive = snake_move(&snake);
        const int speed = snake->orientation == LEFT || snake->orientation == RIGHT;
        setColor(GREY);
        showScore(0);
        Sleep(speed ? SECOND_X : SECOND_Y);
    }
    resetSnake(&snake);
}

int verifyCoord(Snake *snake, const int x, const int y) {
    while (snake != NULL) {
        if (snake->coord.X == x || snake->coord.Y == y) {
            return 0;
        } else {
            snake = snake->next;
        }
    }
    return 1;
}

void appleAppear(Snake *snake) { // DONDE APARECER LA MANZANA
    do {
        apple.X = rand() % ((RIGHT_FRAME - 1) - (LEFT_FRAME + 1)) + (LEFT_FRAME + 1);
        apple.Y = rand() % ((BOTTOM_FRAME - 1) - (TOP_FRAME + 1)) + (TOP_FRAME + 1);
    } while (verifyCoord(snake, apple.X, apple.Y) == 0);
    setColor(LIGHTRED);
    gotoxy(apple.X, apple.Y);
    printf("%c", APPLE);
}

void verifyError(void *arg, const int line) {

    if (arg == NULL) {
        fprintf(stderr, "ERROR, Status : %d", line);
        free(arg);
        exit(1);
    }
}

void gotoxy(int x, int y) {

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};

    SetConsoleCursorPosition(console, pos);
}

void setColor(int value) {
    WORD color;

    HANDLE standarOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(standarOutput, &csbi)) {
        color = (csbi.wAttributes & 0xF0) + (value & 0x0F);
        SetConsoleTextAttribute(standarOutput, color);
    }
    return;
}
