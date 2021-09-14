#include "gui.h"
#include "snake.h"

extern int score;

void showScore(const int increment) {
    setColor(LIGHTCYAN);
    gotoxy(RIGHT_FRAME - 10, TOP_FRAME - 2);
    printf("SCORE: %05d ", score);

    printf("");

    score += increment;
}

void snakeDraw() {
    setColor(LIGHTGREEN);
    const int x = LEFT_FRAME;
    const int y = TOP_FRAME;
    gotoxy(x - 3, y + 5);
    printf("           /^\\/^\\");
    gotoxy(x - 3, y + 6);
    printf("         _|__|  ");
    setColor(WHITE);
    printf("O");
    setColor(LIGHTGREEN);
    printf("|\\");

    // lengua
    setColor(LIGHTRED);
    gotoxy(x - 3, y + 7);
    printf("\\/");
    setColor(LIGHTGREEN);
    printf("     /~     \\_/ \\");
    setColor(LIGHTRED);
    gotoxy(x - 3, y + 8);
    printf(" \\____");
    setColor(LIGHTGREEN);

    printf("|__________/  \\");
    gotoxy(x - 3, y + 9);
    printf("        \\_______      \\");
    gotoxy(x - 3, y + 10);
    printf("                `\\     \\                 \\");
    gotoxy(x - 3, y + 11);
    printf("                  |     |                  \\");
    gotoxy(x - 3, y + 12);
    printf("                 /      /                    \\");
    gotoxy(x - 3, y + 13);
    printf("                /     /                       \\\\");
    gotoxy(x - 3, y + 14);
    printf("              /      /                         \\ \\");
    gotoxy(x - 3, y + 15);
    printf("             /     /                            \\  \\");
    gotoxy(x - 3, y + 16);
    printf("           /     /             _----_            \\   \\");
    gotoxy(x - 3, y + 17);
    printf("          /     /           _-~      ~-_         |   |");
    gotoxy(x - 3, y + 18);
    printf("         (      (        _-~    _--_    ~-_     _/   |");
    gotoxy(x - 3, y + 19);
    printf("          \\      ~-____-~    _-~    ~-_    ~-_-~    /");
    gotoxy(x - 3, y + 20);
    printf("            ~-_           _-~          ~-_       _-~");
    gotoxy(x - 3, y + 21);
    printf("               ~--______-~                ~-___-~");
}

void snakeTitle() {
    setColor(LIGHTCYAN);
    const int x = (RIGHT_FRAME + LEFT_FRAME) / 2 - 18;
    const int y = TOP_FRAME;
    gotoxy(x, y - 3);
    printf(" _______ ______  _______ ___ ___  _______ ");
    gotoxy(x, y - 2);
    printf("|   _   |   _  \\|   _   |   Y   )|   _   |");
    gotoxy(x, y - 1);
    printf("|   1___|.  |   |.  1   |.  1  / |.  1___|");
    gotoxy(x, y);
    printf("|____   |.  |   |.  _   |.  _  \\ |.  __)_ ");
    gotoxy(x, y + 1);
    printf("|:  1   |:  |   |:  |   |:  |   \\|:  1   |");
    gotoxy(x, y + 2);
    printf("|::.. . |::.|   |::.|:. |::.| .  |::.. . |");
    gotoxy(x, y + 3);
    printf("`-------`--- ---`--- ---`--- ---'`-------'");
    setColor(GREY);
}

void snakeDraw2() {

    //?https://ascii.co.uk/art/snake

    setColor(GREEN);
    const int y = BOTTOM_FRAME + 4;
    gotoxy(0, y + 1);
    printf("                        __    __    __    __           ");
    gotoxy(0, y + 2);
    printf("                       /  \\  /  \\  /  \\  /  \\           ");
    gotoxy(0, y + 3);
    setColor(BROWN);
    printf("______________________");
    setColor(GREEN);
    printf("/  ");
    setColor(BROWN);
    printf("__");
    setColor(GREEN);
    printf("\\/  ");
    setColor(BROWN);
    printf("__");
    setColor(GREEN);
    printf("\\/  ");
    setColor(BROWN);
    printf("__");
    setColor(GREEN);
    printf("\\/  ");
    setColor(BROWN);
    printf("__");
    setColor(GREEN);
    printf("\\");
    setColor(BROWN);
    printf("_____________________________ ");

    gotoxy(0, y + 4);
    setColor(BROWN);
    printf("_____________________");
    setColor(GREEN);
    printf("/  /");
    setColor(BROWN);
    printf("__");
    setColor(GREEN);
    printf("/  /");
    setColor(BROWN);
    printf("__");
    setColor(GREEN);
    printf("/  /");
    setColor(BROWN);
    printf("__");
    setColor(GREEN);
    printf("/  /");
    setColor(BROWN);
    printf("________________________________");
    setColor(GREEN);
    gotoxy(0, y + 5);
    printf("                     | / \\   / \\   / \\   / \\  \\____           ");
    gotoxy(0, y + 6);
    printf("                     |/   \\_/   \\_/   \\_/   \\    o \\           ");
    gotoxy(0, y + 7);
    printf("                                             \\_____/");
    setColor(LIGHTRED);
    printf("--<           ");
    setColor(GREY);
}

void showInstructions() {
    const int arrow_right = 16;
    const int arrow_left = 17;
    const int arrow_down = 31;
    const int arrow_up = 30;
    const int x = 20;
    const int y = 0;
    setColor(YELLOW);
    gotoxy(x + 2, y + 2);
    printf("%c", arrow_up);
    gotoxy(x + 0, y + 3);
    printf("%c %c %c", arrow_left, arrow_down, arrow_right);
    setColor(GREY);

    gotoxy(x - 8, y);
    printf("Arrow keys for movement");

    lineHori(x - 8, y + 1, 23);
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
    system("cls");
    showScore(0);
    setColor(LIGHTMAGENTA);
    printFrame(LEFT_FRAME - 1, TOP_FRAME - 1, RIGHT_FRAME + 1, BOTTOM_FRAME + 1);
    gotoxy(LEFT_FRAME + 7, TOP_FRAME);
    printf(" _____ _____ _____ _____ _____ ");
    gotoxy(LEFT_FRAME + 7, TOP_FRAME + 1);
    printf("|   __|     |     | __  |   __|");
    gotoxy(LEFT_FRAME + 7, TOP_FRAME + 2);
    printf("|__   |   --|  |  |    -|   __|");
    gotoxy(LEFT_FRAME + 7, TOP_FRAME + 3);
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

    x += 16;
    const int y = TOP_FRAME + 5;

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
    Beep(900, 100);
    Beep(900, 200);
    Beep(900, 500);

    free(array);
    array = NULL;
}

void printNumber0(const int x, const int y) {
    gotoxy(x + 1, y);
    printf("___ ");
    gotoxy(x, y + 1);
    printf("|   |");
    gotoxy(x, y + 2);
    printf("| | |");
    gotoxy(x, y + 3);
    printf("|___|");
}

void printNumber1(const int x, const int y) {
    gotoxy(x + 1, y);
    printf("___   ");
    gotoxy(x, y + 1);
    printf("|_  |  ");
    gotoxy(x + 1, y + 2);
    printf("_| |_ ");
    gotoxy(x, y + 3);
    printf("|_____|");
}

void printNumber2(const int x, const int y) {
    gotoxy(x + 1, y);
    printf("___ ");
    gotoxy(x, y + 1);
    printf("|_  |");
    gotoxy(x, y + 2);
    printf("|  _|");
    gotoxy(x, y + 3);
    printf("|___|");
}

void printNumber3(const int x, const int y) {
    gotoxy(x + 1, y);
    printf("___ ");
    gotoxy(x, y + 1);
    printf("|_  |");
    gotoxy(x, y + 2);
    printf("|_  |");
    gotoxy(x, y + 3);
    printf("|___|");
}

void printNumber4(const int x, const int y) {
    gotoxy(x + 1, y);
    printf("___ ");
    gotoxy(x, y + 1);
    printf("| | |");
    gotoxy(x, y + 2);
    printf("|_  |");
    gotoxy(x + 2, y + 3);
    printf("|_|");
}

void printNumber5(const int x, const int y) {
    gotoxy(x + 1, y);
    printf("___ ");
    gotoxy(x, y + 1);
    printf("|  _|");
    gotoxy(x, y + 2);
    printf("|_  |");
    gotoxy(x, y + 3);
    printf("|___|");
}

void printNumber6(const int x, const int y) {
    gotoxy(x + 1, y);
    printf("___ ");
    gotoxy(x, y + 1);
    printf("|  _|");
    gotoxy(x, y + 2);
    printf("|_  |");
    gotoxy(x, y + 3);
    printf("|___|");
}

void printNumber7(const int x, const int y) {
    gotoxy(x + 1, y);
    printf("___ ");
    gotoxy(x, y + 1);
    printf("|_  |");
    gotoxy(x + 2, y + 2);
    printf("| |");
    gotoxy(x + 2, y + 3);
    printf("|_|");
}

void printNumber8(const int x, const int y) {
    gotoxy(x + 1, y);
    printf("___ ");
    gotoxy(x, y + 1);
    printf("| . |");
    gotoxy(x, y + 2);
    printf("| . |");
    gotoxy(x, y + 3);
    printf("|___|");
}

void printNumber9(const int x, const int y) {
    gotoxy(x + 1, y);
    printf("___ ");
    gotoxy(x, y + 1);
    printf("| . |");
    gotoxy(x, y + 2);
    printf("|_  |");
    gotoxy(x, y + 3);
    printf("|___|");
}

void cleanLineHori(const int y) {
    for (int i = 0; i < 75; i++) {
        gotoxy(i, y);
        printf(" ");
    }
}

void cleanLineVert(const int x) {
    for (int i = 0; i < 6; i++) {
        gotoxy(x, 19 + i);
        printf("  ");
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
    for (int i = x; i < length + x; i++) {
        gotoxy(i, y);
        printf("%c", HORI);
    }
}

void lineVert(int x, int y, int length) {
    const int VERT = 179;
    for (int i = y; i < length + y; i++) {
        gotoxy(x, i);
        printf("%c", VERT);
    }
}
