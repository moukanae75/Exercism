#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main() {
    int hour,minute, secand;
     hour = minute = secand = 0;

     while (1)
     {
        system("cls");

        printf("%02d : %02d : %02d",hour,minute,secand);

        

        secand++;

        if (secand == 60) {
            minute += 1;
            secand = 0;
        }
        if (minute ==60) {
            hour += 1;
            minute = 0;
        }

        if (hour == 24 ) {
            hour =0;
            minute = 0;
            secand = 0; 
        }
        Sleep(1000);
     }
     return 0;
     
}