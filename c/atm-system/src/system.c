
#include "header.h"

const char *RECORDS = "./data/records.txt";

struct User getUserFromFile(struct User *u,int choix) {
    struct User v;
    FILE *ptr = fopen("./data/users.txt", "r");
    if (ptr == NULL) {
        perror("Error opening the file");
        return v; // Failure
    }
    if (choix == 1)
    {
        while (fscanf(ptr, "%d %49s %49s", &v.id, v.name, v.password) != EOF) {
        if (strcmp(u->name,v.name) == 0)
        {
            printf("Ifound %s iD : %d",v.name,v.id);
            break;
        
        }
    }
    return v;
    }

    int found = 0; // Flag to indicate if any user data was read
    while (fscanf(ptr, "%d %49s %49s", &v.id, v.name, v.password) != EOF) {
        printf("ID: %d\nName: %s\nPassword: %s\n", v.id, v.name, v.password);
        found = 1; // Set flag to indicate success
    }

    fclose(ptr);

    if (!found) {
        printf("No user data found in the file.\n");
        return *u; // Failure
    }
    
    

    return *u;
}

int getAccountFromFile(FILE *ptr, char name[50], struct Record *r)
{
    return fscanf(ptr, "%d %d %s %d %d/%d/%d %s %d %lf %s",
                  &r->id,
		  &r->userId,
		  name,
                  &r->accountNbr,
                  &r->deposit.month,
                  &r->deposit.day,
                  &r->deposit.year,
                  r->country,
                  &r->phone,
                  &r->amount,
                  r->accountType) != EOF;
}

void saveAccountToFile(FILE *ptr, struct User u, struct Record r)
{
    fprintf(ptr, "%d %d %s %d %d/%d/%d %s %d %.2lf %s\n\n",
            r.id,
	    u.id,
	    u.name,
            r.accountNbr,
            r.deposit.month,
            r.deposit.day,
            r.deposit.year,
            r.country,
            r.phone,
            r.amount,
            r.accountType);
}

void stayOrReturn(int notGood, void f(struct User u), struct User u)
{
        #ifdef _WIN32
    #define LOSE_SYMBOL "[X]" 
    #else
    #define LOSE_SYMBOL "✖"  
    #endif
    int option;
    if (notGood == 0)
    {
        system("clear||cls");
        printf("\n%s Record not found!!\n",LOSE_SYMBOL);
    invalid:
        printf("\nEnter 0 to try again, 1 to return to main menu and 2 to exit:");
        scanf("%d", &option);
        if (option == 0)
            f(u);
        else if (option == 1)
            mainMenu(u);
        else if (option == 2)
            exit(0);
        else
        {
            printf("Insert a valid operation!\n");
            goto invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &option);
    }
    if (option == 1)
    {
        system("clear");
        mainMenu(u);
    }
    else
    {
        system("clear");
        exit(1);
    }
}

void success(struct User u)
{
    #ifdef _WIN32
    #define SUCCESS_SYMBOL "[OK]" 
    #else
    #define SUCCESS_SYMBOL "✔"  
    #endif
    int option;
    printf("\n%s Success!\n\n", SUCCESS_SYMBOL);
invalid:
    printf("Enter 1 to go to the main menu and 0 to exit!\n");
    scanf("%d", &option);
    system("clear");
    if (option == 1)
    {
        mainMenu(u);
    }
    else if (option == 0)
    {
        exit(1);
    }
    else
    {
        printf("Insert a valid operation!\n");
        goto invalid;
    }
}

void createNewAcc(struct User u)
{
    struct Record r;
    struct Record cr;
    char userName[50];
    FILE *pf = fopen(RECORDS, "a+");

noAccount:
    system("clear||cls");
    printf("\t\t\t===== New record =====\n");
    printf("--Welcom %s\nid: %d\n",u.name,u.id);

    printf("\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d", &r.deposit.month, &r.deposit.day, &r.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d", &r.accountNbr);

    while (getAccountFromFile(pf, userName, &cr))
    {
        if (strcmp(userName, u.name) == 0 && cr.accountNbr == r.accountNbr)
        {
            printf("✖ This Account already exists for this user\n\n");
            goto noAccount;
        }
    }

    printf("\nEnter the country:");
    scanf("%s", r.country);
    printf("\nEnter the phone number:");
    scanf("%d", &r.phone);
    printf("\nEnter amount to deposit: $");
    scanf("%lf", &r.amount);
    printf("\nChoose the type of account:\n\t-> saving\n\t-> current\n\t-> fixed01(for 1 year)\n\t-> fixed02(for 2 years)\n\t-> fixed03(for 3 years)\n\n\tEnter your choice:");
    scanf("%s", r.accountType);
    FILE *ptr1 = fopen(RECORDS,"r");
    while (fscanf(ptr1, "%d %d %s %d %d/%d/%d %s %d %lf %s",
                  &cr.id,
		  &cr.userId,
		  cr.name,
                  &cr.accountNbr,
                  &cr.deposit.month,
                  &cr.deposit.day,
                  &cr.deposit.year,
                  cr.country,
                  &cr.phone,
                  &cr.amount,
                  cr.accountType) != EOF)
    {
        r.id = cr.id + 1;
    }
    printf("\n");
    

    printf("%d",r.id);
    
    saveAccountToFile(pf, u, r);
    fclose(ptr1);

    fclose(pf);
    success(u);
}

void updAccount(struct User u, struct Record r) {
    const char *temp_file_name = "./data/temp.txt";
    FILE *file = fopen(RECORDS, "r");
    FILE *temp_file = fopen(temp_file_name, "w");
    system("clear||cls");

    if (file == NULL || temp_file == NULL) {
        perror("Error opening file");
        
    }

    int nbr,choix;

    printf("\n What is the account number you want update : ");
    scanf("%d",&nbr);
    while (fscanf(file, "%d %d %s %d %d/%d/%d %s %d %lf %s",
                  &r.id,
		  &r.userId,
		  r.name,
                  &r.accountNbr,
                  &r.deposit.month,
                  &r.deposit.day,
                  &r.deposit.year,
                  r.country,
                  &r.phone,
                  &r.amount,
                  r.accountType) != EOF) {
        if (nbr == r.accountNbr) {
            printf("1-> phone number\n2-> country\n\t\tEnter you choice : ");
            scanf("%d",&choix);
            if (choix == 1)
            {
                printf("New phone number : ");
                scanf("%d",&r.phone);
            }else if (choix == 2)
            {
                printf("Your country :");
                scanf(" %49[^\n]", r.country);
            }
            
            
            fprintf(temp_file, "%d %d %s %d %d/%d/%d %s %d %.2lf %s\n\n",
            r.id,
	        r.userId,
	        r.name,
            r.accountNbr,
            r.deposit.month,
            r.deposit.day,
            r.deposit.year,
            r.country,
            r.phone,
            r.amount,
            r.accountType);
        } else {
            fprintf(temp_file, "%d %d %s %d %d/%d/%d %s %d %.2lf %s\n\n",
            r.id,
	        r.userId,
	        r.name,
            r.accountNbr,
            r.deposit.month,
            r.deposit.day,
            r.deposit.year,
            r.country,
            r.phone,
            r.amount,
            r.accountType);
        }
        
    }

    fclose(file);
    fclose(temp_file);

    remove(RECORDS);
    rename(temp_file_name, RECORDS);

    printf("updated successfully.\n");
    success(u);

}

void checkAllAccounts(struct User u)
{
    char userName[100];
    struct Record r;

    FILE *pf = fopen(RECORDS, "r");

    system("clear");
    printf("\t\t====== All accounts from user, %s =====\n\n", u.name);
    while (getAccountFromFile(pf, userName, &r))
    {
        if (strcmp(userName, u.name) == 0)
        {
            printf("_____________________\n");
            printf("\nAccount number:%d\nDeposit Date:%d/%d/%d \ncountry:%s \nPhone number:%d \nAmount deposited: $%.2f \nType Of Account:%s\n",
                   r.accountNbr,
                   r.deposit.day,
                   r.deposit.month,
                   r.deposit.year,
                   r.country,
                   r.phone,
                   r.amount,
                   r.accountType);
        }
    }
    fclose(pf);
    success(u);
}

void checkAccount(struct User u) {
        char userName[100];
    struct Record r;
    int notGood = 0;
    int acc_nbr;
        printf("Enter the account number : ");
        scanf("%d",&acc_nbr);

    FILE *pf = fopen(RECORDS, "r");

    system("clear||cls");
    printf("\t\t====== Accounts from user, %s =====\n\n", u.name);
    while (getAccountFromFile(pf, userName, &r))
    {
        if (acc_nbr == r.accountNbr)
        {
            printf("_____________________\n");
            printf("\nAccount number:%d\nDeposit Date:%d/%d/%d \ncountry:%s \nPhone number:%d \nAmount deposited: %.2f$ \nType Of Account:%s\n",
                   r.accountNbr,
                   r.deposit.day,
                   r.deposit.month,
                   r.deposit.year,
                   r.country,
                   r.phone,
                   r.amount,
                   r.accountType);
            notGood = 1;
            if (strcmp(r.accountType,"saving") == 0)
            {
                
                float interst = (r.amount * 0.07)/12;
                printf("\nYou will get %.2f$ as interest on day %d of every month\n",interst,r.deposit.day);
            }else if (strcmp(r.accountType,"fixed01") == 0)
            {
                float interst = (r.amount * 0.04)/12;
                printf("\nYou will get %.2f$ as interest on day %d of every month\n",interst,r.deposit.day);
            }else if (strcmp(r.accountType,"fixed02") == 0)
            {
                float interst = (r.amount * 0.05)/12;
                printf("\nYou will get %.2f$ as interest on day %d of every month\n",interst,r.deposit.day);
            }else if (strcmp(r.accountType,"fixed03") == 0)
            {
                float interst = (r.amount * 0.08)/12;
                printf("\nYou will get %.2f$ as interest on day %d of every month\n",interst,r.deposit.day);
            }else {
                printf("\nYou will not get interests because the account is of type current\n");
            }
            
            
        }
    }
    fclose(pf);
    stayOrReturn(notGood,checkAccount,u);
}
void makeTransaction(struct User u,struct Record r) {
    const char *temp_file_name = "./data/temp.txt";
    FILE *file = fopen(RECORDS, "r");
    FILE *temp_file = fopen(temp_file_name, "w");
    system("clear||cls");

    if (file == NULL || temp_file == NULL) {
        perror("Error opening file");
        
    }

    int nbr,choix,with;

    printf("\n Enter the account number of the customer : ");
    scanf("%d",&nbr);
    while (fscanf(file, "%d %d %s %d %d/%d/%d %s %d %lf %s",
                  &r.id,
		  &r.userId,
		  r.name,
                  &r.accountNbr,
                  &r.deposit.month,
                  &r.deposit.day,
                  &r.deposit.year,
                  r.country,
                  &r.phone,
                  &r.amount,
                  r.accountType) != EOF) {
        if (nbr == r.accountNbr) {
            if (strstr(r.accountType, "fixed") != NULL)
            {
               printf("X You cannot deposit or withdraw in fixed account");
                    printf("\nEnter 0 to return to menu : ");
                    scanf("%d",&with);
                    fclose(file);
                    fclose(temp_file);
                    remove(temp_file_name);
                    mainMenu(u);
            }
            
            printf("Do you want to:\n\t1-> Withdraw\n\t2-> Deposit\nEnter you choice : ");
            scanf("%d",&choix);
            if (choix == 1)
            {
                printf("Enter the amount you want to Withdraw : ");
                scanf("%d",&with);
                if ((double)with > r.amount)
                {
                    printf("X the amount you chose to withdraw is superior to your balance !\n");
                    printf("\nEnter 0 to return to menu : ");
                    scanf("%d",&with);
                    fclose(file);
                    fclose(temp_file);
                    remove(temp_file_name);
                    mainMenu(u);

                    
                }
                r.amount -= with;
                
            }else if (choix == 2)
            {
                printf("Enter the amount you want to Deposit : ");
                scanf("%d",&with);
                r.amount += with;
            }
            
            
            fprintf(temp_file, "%d %d %s %d %d/%d/%d %s %d %.2lf %s\n\n",
            r.id,
	        r.userId,
	        r.name,
            r.accountNbr,
            r.deposit.month,
            r.deposit.day,
            r.deposit.year,
            r.country,
            r.phone,
            r.amount,
            r.accountType);
        } else {
            fprintf(temp_file, "%d %d %s %d %d/%d/%d %s %d %.2lf %s\n\n",
            r.id,
	        r.userId,
	        r.name,
            r.accountNbr,
            r.deposit.month,
            r.deposit.day,
            r.deposit.year,
            r.country,
            r.phone,
            r.amount,
            r.accountType);
        }
        
    }

    fclose(file);
    fclose(temp_file);

    remove(RECORDS);
    rename(temp_file_name, RECORDS);

    success(u);
}
void removeAccount(struct User u,struct Record r) {
        const char *temp_file_name = "./data/temp.txt";
    FILE *file = fopen(RECORDS, "r");
    FILE *temp_file = fopen(temp_file_name, "w");
    system("clear||cls");

    if (file == NULL || temp_file == NULL) {
        perror("Error opening file");
        
    }

    int nbr,choix,isdeleted = 0;

    printf("\n Enter the account number you want to delete : ");
    scanf("%d",&nbr);
    while (fscanf(file, "%d %d %s %d %d/%d/%d %s %d %lf %s",
                  &r.id,
		  &r.userId,
		  r.name,
                  &r.accountNbr,
                  &r.deposit.month,
                  &r.deposit.day,
                  &r.deposit.year,
                  r.country,
                  &r.phone,
                  &r.amount,
                  r.accountType) != EOF) {
        if (nbr == r.accountNbr) {            
            
            isdeleted = 1;
            printf("\t\t============Dleted Account============\n\n");
                        printf("\nAccount number:%d\nDeposit Date:%d/%d/%d \ncountry:%s \nPhone number:%d \nAmount deposited: %.2f$ \nType Of Account:%s\n",
                   r.accountNbr,
                   r.deposit.day,
                   r.deposit.month,
                   r.deposit.year,
                   r.country,
                   r.phone,
                   r.amount,
                   r.accountType);
            continue;
        } 
        if (isdeleted == 0){
            fprintf(temp_file, "%d %d %s %d %d/%d/%d %s %d %.2lf %s\n\n",
            r.id,
	        r.userId,
	        r.name,
            r.accountNbr,
            r.deposit.month,
            r.deposit.day,
            r.deposit.year,
            r.country,
            r.phone,
            r.amount,
            r.accountType);
        }
        if (isdeleted == 1)
        {
            r.id -= 1;
            fprintf(temp_file, "%d %d %s %d %d/%d/%d %s %d %.2lf %s\n\n",
            r.id,
	        r.userId,
	        r.name,
            r.accountNbr,
            r.deposit.month,
            r.deposit.day,
            r.deposit.year,
            r.country,
            r.phone,
            r.amount,
            r.accountType);
        }
        
        
    }

    fclose(file);
    fclose(temp_file);

    remove(RECORDS);
    rename(temp_file_name, RECORDS);


    success(u);
}
void TransferOwner(struct User u,struct Record r) {
    
}

void fordelay() {
    char spinner[] = { '/', '-', '\\', '\0' };
    printf("\n");
    int count = 0;
    while (1) {
        for (int i = 0; i < 3; i++) {
            printf("\r%c waiting...", spinner[i]);
            Sleep(100);
        }
        count++;
        if (count == 5)
        {
            break;
        }
        
    }
}
