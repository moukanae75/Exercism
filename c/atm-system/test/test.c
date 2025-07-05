#include <stdio.h>
#include <string.h>

int main() {
    char a[50], pass[50];
    strcpy(a, "admin");
    strcpy(pass, "admin");
    if (strcmp(a, pass) == 0 )
    {
        printf("Login successful!\n");
    }
    

}