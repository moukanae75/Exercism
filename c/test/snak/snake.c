#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 30
#define HEIGHT 20

typedef struct {
    int x, y;
} Snake;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    Snake snake[10];
    int n = 1;
    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;

    int food_x = rand() % WIDTH;
    int food_y = rand() % HEIGHT;

    int direction = 1; // 1 - right, 2 - left, 3 - up, 4 - down

    while (1) {
        system("cls");

        // Draw the snake
        for (int i = 0; i < n; i++) {
            gotoxy(snake[i].x, snake[i].y);
            printf("#");
        }

        // Draw the food
        gotoxy(food_x, food_y);
        printf("@");

        // Move the snake
        int prev_x = snake[0].x, prev_y = snake[0].y;
        switch (direction) {
            case 1:
                snake[0].x = (snake[0].x + 1) % WIDTH;
                break;
            case 2:
                snake[0].x = (snake[0].x - 1 + WIDTH) % WIDTH;
                break;
            case 3:
                snake[0].y = (snake[0].y - 1 + HEIGHT) % HEIGHT;
                break;
            case 4:
                snake[0].y = (snake[0].y + 1) % HEIGHT;
                break;
        }

        // Check for collision with food
        if (snake[0].x == food_x && snake[0].y == food_y) {
            n++;
            food_x = rand() % WIDTH;
            food_y = rand() % HEIGHT;
        }

        // Move the rest of the snake
        for (int i = 1; i < n; i++) {
            int temp_x = snake[i].x, temp_y = snake[i].y;
            snake[i].x = prev_x;
            snake[i].y = prev_y;
            prev_x = temp_x;
            prev_y = temp_y;
        }

        // Check for collision with the wall or the snake itself
        for (int i = 1; i < n; i++) {
            if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
                printf("Game over! Your score is %d\n", n - 1);
                return 0;
            }
        }

        // Get the next direction
        if (kbhit()) {
            int ch = getch();
            switch (ch) {
                case 'q':
                case 'Q':
                    direction = 2;
                    break;
                case 'd':
                case 'D':
                    direction = 1;
                    break;
                case 'z':
                case 'Z':
                    direction = 3;
                    break;
                case 's':
                case 'S':
                    direction = 4;
                    break;
            }
        }

        Sleep(100);
    }

    return 0;
}