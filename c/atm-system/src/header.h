#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Date
{
    int month, day, year;
};

// all fields for each record of an account
struct Record
{
    int id;
    int userId;
    char name[100];
    char country[100];
    int phone;
    char accountType[10];
    int accountNbr;
    double amount;
    struct Date deposit;
    struct Date withdraw;
};

struct User
{
    int id;
    char name[50];
    char password[50];
};
//struct User Users[100];
struct User getUserFromFile( struct User *u,int choix);
void fordelay();
void initMenu(struct User *u);




// authentication functions
void loginMenu(char a[50], char pass[50]);
void registerMenu(char a[50], char pass[50]);
const char *getPassword(struct User u);

// system function
void createNewAcc(struct User u);
void mainMenu(struct User u);
void checkAccount(struct User u);
void checkAllAccounts(struct User u);
void updAccount(struct User u,struct Record r);
void makeTransaction(struct User u,struct Record r);
void removeAccount(struct User u,struct Record r);
void TransferOwner(struct User u,struct Record r);
