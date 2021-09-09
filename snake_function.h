#pragma once

#include "snake.h"

typedef struct Snake Node;

Snake *createNode(Snake nNew);
void insertEnd(Snake **head, Snake *nNew);
void resetSnake(Snake **head);

void initSnake(Snake **snake);

void printSnake(Snake *snake);
void clearSnakeBody(Snake *snake);
void updateSnake(Snake **snake);
int snake_move(Snake **snake);
int bitesItself(Snake *snake, const int x, const int y);
void increaseSnake(Snake **snake);