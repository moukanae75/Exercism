#include <stdio.h>
#include <string.h>
#include <windows.h>

void fordelay();
void add_product();


struct date {
    int day;
    int mounth;
    int year;
};

struct {
    char name[50];
    char type[50];
    char code_no[10];
    double price;
    struct date add_date;
    struct date experation_date;
}add,upd,rem;

int main() {
    
    system("cls");
    int choice;   
    printf("\n\t\t\t\033[1;33m*********************************************************");
    printf("\n\t\t\t\033[1;33m*\033[1;31m  __  __              _____    _  __  ______   _______ \033[1;33m*");
    printf("\n\t\t\t*\033[1;31m |  \\/  |     /\\     |  __ \\  | |/ / |  ____| |__   __|\033[1;33m*");
    printf("\n\t\t\t*\033[1;31m | \\  / |    /  \\    | |__) | | ' /  | |__       | |   \033[1;33m*");
    printf("\n\t\t\t*\033[1;31m | |\\/| |   / /\\ \\   |  _  /  |  <   |  __|      | |   \033[1;33m*");
    printf("\n\t\t\t*\033[1;31m | |  | |  / ____ \\  | | \\ \\  | . \\  | |____     | |   \033[1;33m*");
    printf("\n\t\t\t*\033[1;31m |_|  |_| /_/    \\_\\ |_|  \\_\\ |_|\\_\\ |______|    |_|   \033[1;33m*");
    printf("\n\t\t\t*********************************************************");
    printf("\n\n\n\t\t\t            \033[1;32m  WELCOME TO THE MINI-MARKET \n");
    printf("\033[0m");
    printf("\033[1;33m");
    printf("\n\t ____ _____________");
    printf("\n\t| 1. | \033[38;2;255;165;0mAdd product\033[1;33m |");
    printf("\n\t ---- -------------");
    printf("\n\t ____ ________________________________________");
    printf("\n\t| 2. | \033[38;2;255;165;0mupdate information of exesting product\033[1;33m |");
    printf("\n\t ---- ----------------------------------------");
    printf("\n\t ____ _________________");
    printf("\n\t| 3. | \033[38;2;255;165;0mFor transaction\033[1;33m |");
    printf("\n\t ---- -----------------");
    printf("\n\t ____ _______________________________________");
    printf("\n\t| 4. | \033[38;2;255;165;0mcheck the details of existing product\033[1;33m |");
    printf("\n\t ---- ---------------------------------------");
    printf("\n\t ____ _________________________");
    printf("\n\t| 5. | \033[38;2;255;165;0mRemove existing exsting\033[1;33m |");
    printf("\n\t ---- -------------------------");
    printf("\n\t ____ __________________");
    printf("\n\t| 6. | \033[38;2;255;165;0mView All product\033[1;33m |");
    printf("\n\t ---- ------------------");
    printf("\n\t ____ ______");
    printf("\n\t| 7. | \033[38;2;255;165;0mExit\033[1;33m |");
    printf("\n\t ---- ------");
    printf("\n\n\n\n\t\t\t Enter your choice : ");
    printf("\033[0m");
    scanf("%d",&choice);

    if (choice > 7 || choice < 1) {
        printf("Invalid Input, please try again !!");
        fordelay();
        main();
    }
    
    
    switch (choice)
    {
    case 1:
        add_product();
        break;
    case 2:
        update();
        break;
    case 3:
        salle();
        break;
    case 4:
        check();
        break;
    case 5:
        remov();
        break;
    case 6:
        all_product();
        break;
    case 7:
        closed();
        break;        
    }
    

    return 0;
}

void fordelay() {
    for (int i = 0;i<8;i++) {
        if (i == 0) 
                {printf(" .");
                Sleep(500);
                }
                else {
                   printf(".");
                Sleep(500); 
                }
            }
}

void add_product() {
    FILE *ptr;
    ptr = fopen("product.dat","a+");
    fprintf(ptr,"\t\t Product");
}
