#pragma once

#include <math.h>

void snakeTitle();
void snakeDraw();
void snakeDraw2();

void showFinalScore();

void printNumber0(const int x, const int y);
void printNumber1(const int x, const int y);
void printNumber2(const int x, const int y);
void printNumber3(const int x, const int y);
void printNumber4(const int x, const int y);
void printNumber5(const int x, const int y);
void printNumber6(const int x, const int y);
void printNumber7(const int x, const int y);
void printNumber8(const int x, const int y);
void printNumber9(const int x, const int y);

void lineHori(int x, int y, int length);
void lineVert(int x, int y, int length);
void cleanLineHori(const int y);
void cleanLineVert(const int x);

int *toArray(int number);

void showInstructions();
void showScore(const int increment);

void printFrame(const int startX, const int startY, int endX, int endY);
