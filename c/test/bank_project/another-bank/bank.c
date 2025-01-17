#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;

void createAccount(Account accounts[], int *numAccounts) {
    printf("Enter account number: ");
    scanf("%d", &accounts[*numAccounts].accountNumber);
    printf("Enter name: ");
    scanf("%s", accounts[*numAccounts].name);
    printf("Enter initial balance: ");
    scanf("%f", &accounts[*numAccounts].balance);
    (*numAccounts)++;
    printf("Account created successfully!\n");
}

void updateAccount(Account accounts[], int numAccounts) {
    int accountNumber, i;
    printf("Enter account number to update: ");
    scanf("%d", &accountNumber);
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter new name: ");
            scanf("%s", accounts[i].name);
            printf("Enter new balance: ");
            scanf("%f", &accounts[i].balance);
            printf("Account updated successfully!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void transaction(Account accounts[], int numAccounts) {
    int accountNumber, i;
    float amount;
    char type;
    printf("Enter account number for transaction: ");
    scanf("%d", &accountNumber);
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter transaction type (d for deposit, w for withdrawal): ");
            scanf(" %c", &type);
            printf("Enter amount: ");
            scanf("%f", &amount);
            if (type == 'd') {
                accounts[i].balance += amount;
                printf("Deposit successful!\n");
            } else if (type == 'w') {
                if (accounts[i].balance >= amount) {
                    accounts[i].balance -= amount;
                    printf("Withdrawal successful!\n");
                } else {
                    printf("Insufficient balance!\n");
                }
            } else {
                printf("Invalid transaction type!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void checkAccountDetails(Account accounts[], int numAccounts) {
    int accountNumber, i;
    printf("Enter account number to check details: ");
    scanf("%d", &accountNumber);
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void removeAccount(Account accounts[], int *numAccounts) {
    int accountNumber, i, j;
    printf("Enter account number to remove: ");
    scanf("%d", &accountNumber);
    for (i = 0; i < *numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            for (j = i; j < *numAccounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            (*numAccounts)--;
            printf("Account removed successfully!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void viewCustomersList(Account accounts[], int numAccounts) {
    int i;
    printf("Customer List:\n");
    for (i = 0; i < numAccounts; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    Account accounts[100];
    int numAccounts = 0;
    int choice;

    while (1) {
        printf("\nCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");
        printf("1. Create new account\n");
        printf("2. Update information of existing account\n");
        printf("3. For transaction\n");
        printf("4. Check the details of existing account\n");
        printf("5. Remove existing account\n");
        printf("6. View customer's list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                updateAccount(accounts, numAccounts);
                break;
            case 3:
                transaction(accounts, numAccounts);
                break;
            case 4:
                checkAccountDetails(accounts, numAccounts);
                break;
            case 5:
                removeAccount(accounts, &numAccounts);
                break;
            case 6:
                viewCustomersList(accounts, numAccounts);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
