#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *ptr;
    char filename[50];
    char data[100];

    printf("Enter the filename: ");
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove the newline character

    ptr = fopen(filename, "w");
    if (ptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the data to write to the file: ");
    fgets(data, 100, stdin);
    data[strcspn(data, "\n")] = '\0'; // Remove the newline character

    fprintf(ptr, "%s", data);
    fclose(ptr);
    ptr = fopen("cls","r");
    printf("%s",ptr);

    return 0;
}