#include "gui.h"
#include "snake.h"

extern int score;

void showScore(const int increment) {
    gotoxy(RIGHT_FRAME - 9, TOP_FRAME - 2);
    printf("SCORE: %05d ", score);
    score += increment;
}

void showInstructions() {
    int arrow_right = 16;
    int arrow_left = 17;
    int arrow_down = 31;
    int arrow_up = 30;

    const int x = 1;
    const int y = 1;

    gotoxy(x, y + 1);
    printf("Movement keys : ");
    gotoxy(x + 22, y);
    printf("%c", arrow_up);
    gotoxy(x + 20, y + 1);
    printf("%c %c %c", arrow_left, arrow_down, arrow_right);
}

int *toArray(int number) {
    int n = log10(number);
    int i;
    int *numberArray = calloc(n + 1, sizeof(int));
    verifyError(numberArray, 31);
    for (i = n; i >= 0; i--) {
        numberArray[i] = number % 10;
        number /= 10;
    }
    return numberArray;
}

void showFinalScore() {
    gotoxy(LEFT_FRAME + 7, TOP_FRAME + 5);
    printf(" _____ _____ _____ _____ _____ ");
    gotoxy(LEFT_FRAME + 7, TOP_FRAME + 6);
    printf("|   __|     |     | __  |   __|");
    gotoxy(LEFT_FRAME + 7, TOP_FRAME + 7);
    printf("|__   |   --|  |  |    -|   __|");
    gotoxy(LEFT_FRAME + 7, TOP_FRAME + 8);
    printf("|_____|_____|_____|__|__|_____|");

    int *array = toArray(score);
    size_t size = _msize(array) / sizeof(int);

    int x = (RIGHT_FRAME - LEFT_FRAME) / 2;
    for (int i = 0; i < size; i++) {
        if (array[i] == 1) {
            x -= 3;
        } else {
            x -= 2;
        }
    }

    x += 14; // una linea matias
    const int y = TOP_FRAME + 10;

    for (int i = 0; i < size; i++) {
        switch (array[i]) {
            case 0:
                printNumber0(x, y);
                break;
            case 1:
                printNumber1(x, y);
                x += 2;
                break;
            case 2:
                printNumber2(x, y);
                break;
            case 3:
                printNumber3(x, y);
                break;
            case 4:
                printNumber4(x, y);
                break;
            case 5:
                printNumber5(x, y);
                break;
            case 6:
                printNumber6(x, y);
                break;
            case 7:
                printNumber7(x, y);
                break;
            case 8:
                printNumber8(x, y);
                break;
            case 9:
                printNumber9(x, y);
                break;
        }
        x += 4;
    }

    free(array);
    array = NULL;
}

void printNumber0(const int x, const int y) {
    gotoxy(x, y);
    printf(" ___ ");
    gotoxy(x, y + 1);
    printf("|   |");
    gotoxy(x, y + 2);
    printf("| | |");
    gotoxy(x, y + 3);
    printf("|___|");
}

void printNumber1(const int x, const int y) {
    gotoxy(x, y);
    printf(" ___   ");
    gotoxy(x, y + 1);
    printf("|_  |  ");
    gotoxy(x, y + 2);
    printf(" _| |_ ");
    gotoxy(x, y + 3);
    printf("|_____|");
}

void printNumber2(const int x, const int y) {
    gotoxy(x, y);
    printf(" ___ ");
    gotoxy(x, y + 1);
    printf("|_  |");
    gotoxy(x, y + 2);
    printf("|  _|");
    gotoxy(x, y + 3);
    printf("|___|");
}

void printNumber3(const int x, const int y) {
    gotoxy(x, y);
    printf(" ___ ");
    gotoxy(x, y + 1);
    printf("|_  |");
    gotoxy(x, y + 2);
    printf("|_  |");
    gotoxy(x, y + 3);
    printf("|___|");
}

void printNumber4(const int x, const int y) {
    gotoxy(x, y);
    printf(" ___ ");
    gotoxy(x, y + 1);
    printf("| | |");
    gotoxy(x, y + 2);
    printf("|_  |");
    gotoxy(x, y + 3);
    printf("  |_|");
}

void printNumber5(const int x, const int y) {
    gotoxy(x, y);
    printf(" ___ ");
    gotoxy(x, y + 1);
    printf("|  _|");
    gotoxy(x, y + 2);
    printf("|_  |");
    gotoxy(x, y + 3);
    printf("|___|");
}

void printNumber6(const int x, const int y) {
    gotoxy(x, y);
    printf(" ___ ");
    gotoxy(x, y + 1);
    printf("|  _|");
    gotoxy(x, y + 2);
    printf("|_  |");
    gotoxy(x, y + 3);
    printf("|___|");
}

void printNumber7(const int x, const int y) {
    gotoxy(x, y);
    printf(" ___ ");
    gotoxy(x, y + 1);
    printf("|_  |");
    gotoxy(x, y + 2);
    printf("  | |");
    gotoxy(x, y + 3);
    printf("  |_|");
}

void printNumber8(const int x, const int y) {
    gotoxy(x, y);
    printf(" ___ ");
    gotoxy(x, y + 1);
    printf("| . |");
    gotoxy(x, y + 2);
    printf("| . |");
    gotoxy(x, y + 3);
    printf("|___|");
}

void printNumber9(const int x, const int y) {
    gotoxy(x, y);
    printf(" ___ ");
    gotoxy(x, y + 1);
    printf("| . |");
    gotoxy(x, y + 2);
    printf("|_  |");
    gotoxy(x, y + 3);
    printf("|___|");
}

void cleanLine(const int y) {

    for (int i = 0; i < 75; i++) {
        gotoxy(i, y);
        printf(" ");
    }
}

void printFrame(const int startX, const int startY, int endX, int endY) {
    const char topLeftCorner = 201;
    const char topRightCorner = 187;
    const char botLeftCorner = 200;
    const char botRightCorner = 188;
    const char horizontalLine = 205;
    const char verticalLine = 186;

    endX -= startX;
    endY -= startY;

    gotoxy(startX, startY);
    printf("%c", topLeftCorner);

    for (int i = 0; i < endX; i++) {
        printf("%c", horizontalLine);
    }
    printf("%c", topRightCorner);

    for (int i = 1; i < endY; i++) {
        gotoxy(startX, startY + i);
        printf("%c", verticalLine);
        gotoxy(startX + endX + 1, startY + i);
        printf("%c", verticalLine);
    }

    gotoxy(startX, startY + endY);
    printf("%c", botLeftCorner);
    for (int i = 0; i < endX; i++) {
        printf("%c", horizontalLine);
    }
    printf("%c", botRightCorner);
}

void lineHori(int x, int y, int length) {
    const int HORI = 196;
    for (int i = 0; i < length + x; i++) {
        gotoxy(i, y);
        printf("%c", HORI);
    }
}

void lineVert(int x, int y, int length) {
    const int VERT = 179;
    for (int i = 0; i < length + y; i++) {
        gotoxy(x, i);
        printf("%c", VERT);
    }
}