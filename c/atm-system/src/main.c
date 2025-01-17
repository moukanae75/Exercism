#include "header.h"

void mainMenu(struct User u)
{
    struct Record r;
    int option;
    //system("clear");
    printf("\n\n\t\t\t======= ATM =======\n\n");
    printf("\t\t\t--->Welcome %s<--",u.name);
    printf("\n\t\t-->>Choose one of the options below <<--\n");
    printf("\n\t\t[1]- Create a new account\n");
    printf("\n\t\t[2]- Update account information\n");
    printf("\n\t\t[3]- Check accounts\n");
    printf("\n\t\t[4]- Check list of owned account\n");
    printf("\n\t\t[5]- Make Transaction\n");
    printf("\n\t\t[6]- Remove existing account\n");
    printf("\n\t\t[7]- Transfer ownership\n");
    printf("\n\t\t[8]- Exit\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        createNewAcc(u);
        break;
    case 2:
        updAccount(u,r);
        break;
    case 3:
        
        checkAccount(u);
        break;
    case 4:
        checkAllAccounts(u);
        break;
    case 5:
        makeTransaction(u,r);
        break;
    case 6:
       removeAccount(u,r);
        break;
    case 7:
       TransferOwner(u,r);
        // here
        break;
    case 8:
        initMenu(&u);
        break;
    default:
        printf("Invalid operation!\n");
    }
};

void initMenu(struct User *u) {
    int option;

    while (1) { // Infinite loop to handle menu until user chooses to exit
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        printf("\n\n\t\t======= ATM =======\n");
        printf("\n\t\t-->>  login / register :\n");
        printf("\n\t\t[1]- login\n");
        printf("\n\t\t[2]- register\n");
        printf("\n\t\t[3]- exit\n");
        printf("\n\t\t\tEnter your choice: ");
        scanf("%d", &option);
        fordelay();
        switch (option) {
        case 1: { // Login
            while (1) {
                loginMenu(u->name, u->password);
                printf("\nAfter Login:\n");
                printf("Name: %s\n", u->name);
                printf("Password: %s\n", u->password);
                printf("Stored Password: %s\n", getPassword(*u));
                fordelay();

                if (strcmp(u->password, getPassword(*u)) == 0) {
                    printf("\n\nPassword Match!");
                    printf("\nPress 0 to continue: ");
                    scanf("%d", &option);
                    
                    mainMenu(getUserFromFile(u,1));
                    break; // Exit inner loop
                } else {
                    printf("\nWrong password or user name!\n");
                    printf("Press 0 to retry: ");
                    scanf("%d", &option);
                }
            }
            break;
        }
        case 2: // Register
            registerMenu(u->name, u->password);
            break;

        case 3: // Exit
            printf("\nExiting... Goodbye!\n");
            exit(0);

        case 99: { // Debug user data
            // Re-read the file after registration to reflect the latest data
             // Make sure this is the latest data
            
                getUserFromFile(u,0); 
                printf("\nUser Details (Latest):\n");
                printf("Name: %s\n", u->name);
                printf("Password: %s\n", u->password);
            
            printf("\nEnter 0 to return to menu: ");
            int temp;
            scanf("%d", &temp);
            
            break;
        }

        default: // Invalid choice
            printf("\nInvalid option. Please try again!\n");
        }
    }
}



int main()
{
    struct User u;
    
    initMenu(&u);
    mainMenu(u);
    return 0;
}


