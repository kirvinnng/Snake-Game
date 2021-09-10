#include "snake_function.h"
#include "gui.h"
#include "snake.h"

extern COORD apple;

int REWARD_FOR_EATING = 10;

void initSnake(Snake **snake) {
    Snake aux;
    aux.orientation = DOWN;
    aux.coord.X = LEFT_FRAME + 3;
    aux.coord.Y = TOP_FRAME + 1;

    *snake = createNode(aux);
}

int snake_move(Snake **snake) {
    int x = (*snake)->coord.X;
    int y = (*snake)->coord.Y;

    clearSnakeBody(*snake);

    if (GetAsyncKeyState(0x25)) { //  Izquierda

        if ((*snake)->orientation != RIGHT) {
            (*snake)->orientation = LEFT;
        }
    } else if (GetAsyncKeyState(0x27)) { // Derecha

        if ((*snake)->orientation != LEFT) {
            (*snake)->orientation = RIGHT;
        }
    } else if (GetAsyncKeyState(0x26)) { //  Arriba

        if ((*snake)->orientation != DOWN) {
            (*snake)->orientation = UP;
        }
    } else if (GetAsyncKeyState(0x28)) { //  Abajo

        if ((*snake)->orientation != UP) {
            (*snake)->orientation = DOWN;
        }
    }

    switch ((*snake)->orientation) {
        case UP:
            if (y > TOP_FRAME) { // Limite : 5
                y--;
            } else {
                y = BOTTOM_FRAME;
            }
            break;
        case RIGHT:
            if (x < RIGHT_FRAME + 1) { // Limite : 107
                x++;
            } else {
                x = LEFT_FRAME;
            }
            break;
        case DOWN:
            if (y < BOTTOM_FRAME) { // Limite : 24
                y++;
            } else {
                y = TOP_FRAME;
            }
            break;
        case LEFT:
            if (x > LEFT_FRAME) { // Limite x : 13
                x--;
            } else {
                x = RIGHT_FRAME + 1;
            }
            break;
    }

    //* Verificacion de la mordida
    if (x == apple.X && y == apple.Y) {
        appleAppear(*snake);  // Aparicion de la manzana
        increaseSnake(snake); // Si la come incrementa
        showScore(REWARD_FOR_EATING);
        REWARD_FOR_EATING += 5;
    }

    updateSnake(snake);
    (*snake)->coord.X = x;
    (*snake)->coord.Y = y;
    printSnake(*snake);
    fflush(stdout);
    if (bitesItself(*snake, x, y)) {
        return 0;
    } else {
        return 1;
    }
}

int bitesItself(Snake *snake, const int x, const int y) {
    snake = snake->next; // evitamos la cabeza
    while (snake != NULL) {
        if (snake->coord.X == x && snake->coord.Y == y) {
            return 1;
        }

        snake = snake->next;
    }
    return 0;
}

void updateSnake(Snake **snake) {
    Node *new = (*snake)->next;
    Node *prev = (*snake);
    COORD aux;
    int i = 0;
    //* Actualizando los valores de las coordenadas
    while (new != NULL) {
        aux.X = new->coord.X;
        aux.Y = new->coord.Y;
        new->coord.X = prev->coord.X;
        new->coord.Y = prev->coord.Y;
        prev->coord.X = aux.X;
        prev->coord.Y = aux.Y;

        new = new->next; // 3
    }
}

void printSnake(Snake *snake) {
    setColor(LIGHTGREEN);
    while (snake != NULL) {
        gotoxy(snake->coord.X, snake->coord.Y);
        printf("%c", 219);
        snake = snake->next;
    }
}

void clearSnakeBody(Snake *snake) {
    while (snake != NULL) {
        gotoxy(snake->coord.X, snake->coord.Y);
        printf(" ");
        snake = snake->next;
    }
}

void increaseSnake(Snake **snake) {

    Snake aux;
    aux.coord.X = (*snake)->coord.X;
    aux.coord.Y = (*snake)->coord.Y;
    Node *nNew = createNode(aux);
    insertEnd(snake, nNew); // Insertar al final de la cola
}

void insertEnd(Snake **head, Snake *nNew) {
    Node *aux;
    if (*head == NULL) {
        *head = nNew;
    } else {
        aux = *head;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = nNew;
    }
}

Snake *createNode(Snake nNew) {
    Node *aux = (Node *)malloc(sizeof(Node));
    verifyError(aux, 28);
    aux->coord.X = nNew.coord.X;
    aux->coord.Y = nNew.coord.Y;
    aux->orientation = DOWN;
    aux->next = NULL;

    return aux;
}

void resetSnake(Snake **head) {
    Node *aux;
    while (*head != NULL) {

        aux = *head;
        *head = (*head)->next;
        free(aux);
    }
}