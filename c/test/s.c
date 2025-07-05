#include <stdio.h>
#include <windows.h>
#include <math.h>

// Function to create color transition effect
void setRainbowColor(int i) {
    int r = (int)(sin(i * 0.1) * 127 + 128);
    int g = (int)(sin(i * 0.1 + 2) * 127 + 128);
    int b = (int)(sin(i * 0.1 + 4) * 127 + 128);
    printf("\033[38;2;%d;%d;%dm", r, g, b);
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Ensure UTF-8 is used for output
    system("cls"); // Clear the console

    // Enable ANSI colors
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    const char* lines[] = {
        "             _____       ____     _    _     __  __     _____               ",
        "            / ____|     / __ \\   | |  | |   |  \\/  |   |_   _|      /\\      ",
        "           | (___      | |  | |  | |  | |   | \\  / |     | |       /  \\     ",
        "            \\___ \\     | |  | |  | |  | |   | |\\/| |     | |      / /\\ \\    ",
        "            ____) |    | |  | |  | |__| |   | |  | |    _| |_    / ____ \\   ",
        "           |_____/      \\____/    \\_____/   |_|  |_|   |_____|  /_/    \\_\\  ",
                "                                                                            ",   
        "                               ******       ******                          ",   
        "                             **********   **********                        ",
        "                           ************* *************                      ",
        "                          *****************************                     ",
        "                          *****************************                     ",
        "                          ******** I LOVE YOU *********                     ",
        "                           ***************************                      ",
        "                             ***********************                        ",
        "                               *******************                          ",
        "                                 ***************                            ",
        "                                   ***********                              ",
        "                                     *******                                ",
        "                                       ***                                  ",
        "                                        *                                   "
    };

    int numLines = sizeof(lines) / sizeof(lines[0]);
    
    // Typing animation with rainbow colors
    for (int i = 0; i < numLines; i++) {
        for (int j = 0; lines[i][j] != '\0'; j++) {
            setRainbowColor(i + j);
            printf("%c", lines[i][j]);
            fflush(stdout);
            Sleep(5);
        }
        printf(" ♥\n");  // UTF-8 heart
    }

    // Pulsing heart animation
    printf("\n\n");
    const char* hearts[] = {"♥", "♡"};
    for (int i = 0; i < 10; i++) {
        printf("\r\033[31m%s", hearts[i % 2]);  // Red color
        fflush(stdout);
        Sleep(500);
    }

    // Final message with fade effect
    printf("\n\n");
    const char* message = "Thanks for watching! <3\nFrom: YOUR MED <3";
    for (int i = 0; message[i] != '\0'; i++) {
        setRainbowColor(i * 2);
        printf("%c", message[i]);
        fflush(stdout);
        Sleep(100);
    }

    printf("\033[0m\n");  // Reset color
    Sleep(20000); // Pause for a second before clearing the screen

     // Reset color
    return 0;
}
