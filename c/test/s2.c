#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdbool.h>

#define HEART_EMOJI "\xF0\x9F\x92\x96"  // UTF-8 code for 💖
#define HEART_ALT "<3"  // Fallback ASCII heart

// Color structure for smooth transitions
typedef struct {
    int r, g, b;
} Color;

// Function for smooth color transition
Color getTransitionColor(float progress) {
    Color c;
    c.r = (int)(sin(progress) * 127 + 128);
    c.g = (int)(sin(progress + 2) * 127 + 128);
    c.b = (int)(sin(progress + 4) * 127 + 128);
    return c;
}

void setColor(Color c) {
    printf("\033[38;2;%d;%d;%dm", c.r, c.g, c.b);
}

// Clear screen
void clear() {
    system("cls");
}

// Simulate typing effect
void typeText(const char* text, int delay, bool rainbow) {
    static float progress = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (rainbow) {
            Color c = getTransitionColor(progress);
            setColor(c);
            progress += 0.1;
        }
        printf("%c", text[i]);
        fflush(stdout);
        Sleep(delay);
    }
}

// Draw a heart with different "sizes"
void drawHeart(int size, Color c) {
    clear();
    setColor(c);

    if (size == 1) {
        printf("     **     **\n");
        printf("   ****** ******\n");
        printf("  ***************\n");
        printf(" *****************\n");
        printf("  ***************\n");
        printf("   *************\n");
        printf("     *********\n");
        printf("       *****\n");
        printf("        ***\n");
        printf("         *\n");
    } else if (size == 2) {
        printf("      ****     ****\n");
        printf("   ********** **********\n");
        printf("  *************************\n");
        printf(" ***************************\n");
        printf("  *************************\n");
        printf("   ***********************\n");
        printf("     *******************\n");
        printf("       ***************\n");
        printf("         ***********\n");
        printf("           *******\n");
        printf("             ***\n");
        printf("              *\n");
    } else {
        printf("     ******       ******\n");
        printf("   **********   **********\n");
        printf(" ************* *************\n");
        printf("*****************************\n");
        printf("*****************************\n");
        printf("*****************************\n");
        printf(" ***************************\n");
        printf("   ***********************\n");
        printf("     *******************\n");
        printf("       ***************\n");
        printf("         ***********\n");
        printf("           *******\n");
        printf("             ***\n");
        printf("              *\n");
    }

    // Add sparkles around the heart
    if (size == 3) {
        COORD pos;
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        for (int i = 0; i < 5; i++) {
            pos.X = rand() % 50;
            pos.Y = rand() % 15;
            SetConsoleCursorPosition(hOut, pos);
            printf("✨");
        }
    }
}

int main() {
    // Set UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // Enable ANSI escape sequences
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    // Smooth heartbeat animation
    float progress = 0;
    for (int i = 0; i < 8; i++) {
        for (float scale = 1; scale <= 3; scale += 0.5) {
            Color c = getTransitionColor(progress);
            drawHeart((int)scale, c);
            progress += 0.2;
            Sleep(100);
        }
    }

    // Animated message with rainbow colors
    clear();
    drawHeart(3, (Color){255, 0, 0});

    const char* messages[] = {
        "\n\n" HEART_EMOJI " Dear Love " HEART_EMOJI "\n\n",
        // or use the fallback version if emojis don't display correctly:
        // "\n\n" HEART_ALT " Dear Love " HEART_ALT "\n\n",
        "Every beat of my heart...\n",
        "Is a melody singing your name...\n",
        "Every moment with you...\n",
        "Makes life a beautiful game...\n\n",
        "You are my sunshine (*)\n",
        "My starlight (*)\n",
        "My everything (*)\n\n",
        "Forever Yours " HEART_ALT "\n"
    };

    for (int i = 0; i < sizeof(messages)/sizeof(messages[0]); i++) {
        typeText(messages[i], 50, true);
        Sleep(300);
    }

    // Final heartbeat animation
    for (int i = 0; i < 5; i++) {
        printf("\n\n           \033[38;2;255;0;0m%s I LOVE YOU %s\033[0m", HEART_ALT, HEART_ALT);
        Sleep(500);
        printf("\r           \033[38;2;255;100;100m%s I LOVE YOU %s\033[0m", HEART_ALT, HEART_ALT);
        Sleep(500);
    }

    printf("\n\nPress any key to exit...");
    getchar();
    return 0;
}
