#ifdef _WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define USERS "./data/users.txt"

void disableEcho() {
#ifdef _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & ~(ENABLE_ECHO_INPUT));
#else
    struct termios oflags, nflags;
    tcgetattr(fileno(stdin), &oflags);
    nflags = oflags;
    nflags.c_lflag &= ~ECHO;
    nflags.c_lflag |= ECHONL;
    tcsetattr(fileno(stdin), TCSANOW, &nflags);
#endif
}

void enableEcho() {
#ifdef _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode | ENABLE_ECHO_INPUT);
#else
    struct termios oflags;
    tcgetattr(fileno(stdin), &oflags);
    oflags.c_lflag |= ECHO;
    tcsetattr(fileno(stdin), TCSANOW, &oflags);
#endif
}

void loginMenu(char a[50], char pass[50]) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    printf("\n\n\n\t\t\t\t   Bank Management System\n\t\t\t\t\t User Login:");
    scanf(" %49[^\n]", a);

    disableEcho();
    printf("\n\n\n\n\n\t\t\t\tEnter the password to login:");
    scanf(" %49[^\n]", pass);
    enableEcho();
}

void registerMenu(char a[50], char pass[50]) {
    struct User *u;
    int id = 0, choice;
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    FILE *ptr = fopen(USERS, "a+");
    if (!ptr) {
        perror("Error opening file");
        exit(1);
    }

    while (fscanf(ptr, "%d %49s %49s", &id, a, pass) != EOF) { }

    printf("\n\n\t\t\tEnter your name: ");
    scanf(" %49[^\n]", a);
    printf("\n\n\t\t\tEnter your password: ");
    scanf(" %49[^\n]", pass);

    fprintf(ptr, "%d %s %s\n", id + 1, a, pass);
    fclose(ptr);
    printf("\n✔ Your Registration Success!");
    printf("\nEnter 0 to return to login: ");
    scanf("%d", &choice);
    initMenu(u);
}

const char *getPassword(struct User u) {
    FILE *fp;
    struct User userChecker;
    char *password = NULL;

    if ((fp = fopen(USERS, "r")) == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while (fscanf(fp, "%d %49s %49s", &userChecker.id, userChecker.name, userChecker.password) != EOF) {
        if (strcmp(userChecker.name, u.name) == 0) {
            password = malloc(strlen(userChecker.password) + 1);
            if (!password) {
                perror("Memory allocation failed");
                fclose(fp);
                exit(1);
            }
            strcpy(password, userChecker.password);
            fclose(fp);
            return password;
        }
    }

    fclose(fp);
    return "no user found";
}











//this code for linux
// #include <termios.h>
// #include "header.h"

// char *USERS = "./data/users.txt";

// void loginMenu(char a[50], char pass[50])
// {
//     struct termios oflags, nflags;

//     system("clear");
//     printf("\n\n\n\t\t\t\t   Bank Management System\n\t\t\t\t\t User Login:");
//     scanf("%s", a);

//     // disabling echo
//     tcgetattr(fileno(stdin), &oflags);
//     nflags = oflags;
//     nflags.c_lflag &= ~ECHO;
//     nflags.c_lflag |= ECHONL;

//     if (tcsetattr(fileno(stdin), TCSANOW, &nflags) != 0)
//     {
//         perror("tcsetattr");
//         return exit(1);
//     }
//     printf("\n\n\n\n\n\t\t\t\tEnter the password to login:");
//     scanf("%s", pass);

//     // restore terminal
//     if (tcsetattr(fileno(stdin), TCSANOW, &oflags) != 0)
//     {
//         perror("tcsetattr");
//         return exit(1);
//     }
// };

// const char *getPassword(struct User u)
// {
//     FILE *fp;
//     struct User userChecker;

//     if ((fp = fopen("./data/users.txt", "r")) == NULL)
//     {
//         printf("Error! opening file");
//         exit(1);
//     }

//     while (fscanf(fp, "%s %s", userChecker.name, userChecker.password) != EOF)
//     {
//         if (strcmp(userChecker.name, u.name) == 0)
//         {
//             fclose(fp);
//             char *buff = userChecker.password;
//             return buff;
//         }
//     }

//     fclose(fp);
//     return "no user found";
// }