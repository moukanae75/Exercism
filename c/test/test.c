#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int i,j ;
int main_exit;
void closed();
void fordelay(int j);
void menu();
void new_acc();
void edit();
void transcat();
void see();
void erase();
void view_list();

struct date
{
    int mounth,day,year;
};
struct 
{
    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
}add,upd,check,rem,transaction;

unsigned int sec = 0;
clock_t stopclock = CLOCKS_PER_SEC;

// Global variables
HWND hToolbar;
HWND hMainWnd;
HINSTANCE hInst;

// Toolbar button IDs
#define ID_NEW_ACC    101
#define ID_TRANSACTION 102
#define ID_VIEW_LIST  103
#define ID_EXIT       104

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            INITCOMMONCONTROLSEX icex;
            icex.dwSize = sizeof(icex);
            icex.dwICC = ICC_BAR_CLASSES;
            InitCommonControlsEx(&icex);

            hToolbar = CreateWindowEx(0, TOOLBARCLASSNAME, NULL,
                                      WS_CHILD | WS_VISIBLE | TBSTYLE_WRAPABLE,
                                      50, 50, 100, 30, hwnd,(HMENU)101 , (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

            if (!hToolbar) {
                MessageBox(hwnd, "Toolbar creation failed!", "Error", MB_OK | MB_ICONERROR);
            }

            TBBUTTON tbButtons[] = {
                { MAKELONG(STD_FILENEW, 0), 101, TBSTATE_ENABLED, BTNS_BUTTON, {0}, 0, (INT_PTR)"New Account" },
                { MAKELONG(STD_FILEOPEN, 0), 102, TBSTATE_ENABLED, BTNS_BUTTON, {0}, 0, (INT_PTR)"Transaction" },
                { MAKELONG(STD_FILESAVE, 0), 103, TBSTATE_ENABLED, BTNS_BUTTON, {0}, 0, (INT_PTR)"View List" },
                { MAKELONG(STD_DELETE, 0), 104, TBSTATE_ENABLED, BTNS_BUTTON, {0}, 0, (INT_PTR)"Exit" }
            };

            SendMessage(hToolbar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
            SendMessage(hToolbar, TB_ADDBUTTONS, sizeof(tbButtons) / sizeof(TBBUTTON), (LPARAM)&tbButtons);
            SendMessage(hToolbar, TB_AUTOSIZE, 20, 14);

            return 0;
        }
        case WM_SIZE:
            SendMessage(hToolbar, TB_AUTOSIZE, 15, 15);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(5);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    hInst = hInstance;
    const char CLASS_NAME[] = "SampleWindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, "Toolbar Example",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL);

    if (!hwnd) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 20, 20)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}



void main() {
    char pass[15],password[15] = "mohamed";
    int i = 0;
    printf("\n\n\t Enter the password to login :");
    printf("\033[30;40m");
    scanf("%s",pass);
    printf("\033[0m");
    if(strcmp(pass,password)==0)
    {
        system("cls");
        printf("\n\n Password match ! Loading");
        
        fordelay(1);
        
        menu();
    }
    else
    {
        system("cls");
        printf("\n\n Password match ! Loading");
        fordelay(1);
        printf("\033c");
        printf("\n\n Wrong Password !!!\n");
        printf("\033[1;31m");
        printf("\t\t       / \\        \n");
        printf("\t\t      / | \\         \n");
        printf("\t\t     /  |  \\    \n");
        printf("\t\t    /   *   \\  \n");
        printf("\t\t   /_________\\      \n");
        printf("\033[0m");
        //login_try :
        printf("\n Enter 1 to try again and 0 to exit :");
        scanf("%d",&main_exit);
        if (main_exit == 1)
        {
            system("cls");
            main();
        }
        else if (main_exit == 0)
        {
            closed();
        }
        
        
    }
}
void menu(){
    int choice;
    //printf("\033c");
    system("cls");
    printf("\n");
    printf("\33[1;31m");
    printf("\n\n\t\t\t\t CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\t          \033[1;32m  WELCOME TO THE MENU \n");
    printf("\033[0m");
    printf("\033[1;33m");
    printf("\n\n\t1.Create new account \n\n\t2.update information of exesting account \n\n\t3.For transaction\n\n\t4.check the details of existing account\n\n\t5.Remove existing account \n\n\t6.View customer's list \n\n\t7.Exit \n\n\n\n\t\t\t Enter your choice :");
    printf("\033[0m");
    scanf("%d",&choice);
    system("cls");
    printf("\033c");
    char ch;
    while (1)
    {
        printf("\n\tPress any button to continue or press (ESC) to return to menu :");
        ch = getch();
        if (ch == 27)
        {
           menu();
           
           
        }
        
    switch (choice)
    {
    case 1:new_acc();
        break;
    case 2:edit();
        break;
    case 3:transcat();
        break;
    case 4:see();
        break;
    case 5:erase();
        break;
    case 6:view_list();
        break;
    case 7:closed();
        return;
    }
    }
    
    
    
}

void fordelay(int j) {
    while (sec < j)
    {
        if (clock() > stopclock)
        {
            stopclock += 10;
            for (int i = 0;i<8;i++) {
                printf(".");
                Sleep(500);
            }
            
            fflush(stdout);
            sec++;
        }
        
    }
    
}

void new_acc()
{
    int choice;
    FILE *ptr;
    ptr = fopen("record.dat","a+");
    
    if (ptr == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    account_no:
    system("cls");
    printf("\t\t\t         ADD RECORD ");
    printf("\n\n\n Enter today's date (mm/dd/yyyy) :");
    scanf("%d/%d/%d",&add.deposit.mounth,&add.deposit.day,&add.deposit.year);
    printf("%d/%d/%d\n",add.deposit.mounth,add.deposit.day,add.deposit.year);
    printf("Enter the account number :");
    scanf("%d",&add.acc_no);
    printf("%d",add.acc_no);
    
    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n", &check.acc_no, check.name, &check.dob.mounth, &check.dob.day, &check.dob.year, &check.age, check.address, check.citizenship, &check.phone, check.acc_type, &check.amt, &check.deposit.mounth, &check.deposit.day, &check.deposit.year) != EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            printf("Account now already in use  !");
            Sleep(2000);
            goto account_no ;
        }
        
    }
    //add.acc_no = check.acc_no;
    printf("%d",add.acc_no);
    printf("\n Enter the name :");
    scanf("%s",add.name);
    printf("%s",add.name);
    printf("\n Enter the date of the birth (mm/dd/yyyy) :");
    scanf("%d/%d/%d",&add.dob.mounth,&add.dob.day,&add.dob.year);
    printf("%d/%d/%d",add.dob.mounth,add.dob.day,add.dob.year);
    printf("\n Enter the age :");
    scanf("%d",&add.age);
    printf("%d",add.age);
    printf("\n Enter the address :");
    scanf("%s",add.address);
    printf("%s",add.address);
    printf("\n Enter the citizenship number :");
    scanf("%s",add.citizenship);
    printf("%s",add.citizenship);
    printf("\n Enter the phone number :");
    scanf("%lf",&add.phone);
    printf("%lf",add.phone);
    printf("\n Type of account : \n\t #Saving \n\t #Current \n\t#Fixed1(for 1 year) \n\t#Fixed2(for 2 years) \n\t#Fixed3(for 3 yers)");
    scanf("%s",add.acc_type);
    printf("%s",add.acc_type);

    fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",add.acc_no,add.name,add.dob.mounth,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.mounth,add.deposit.day,add.deposit.year);
    fclose(ptr);
    printf("\n Account created successfully !!");

    add_invalid :
    printf("\n\n\n\t Enter 1 to go to the main menu and 0 to Exit :\n ");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
    {
        menu();
    }
    else if (main_exit == 0)
    {
        closed();
    }
    else{
        printf("\n Invalid Input!!");
        goto add_invalid;
    }
    
}

void edit()
{
    int choice,test = 0;
    FILE *old,*newrec;
    old = fopen("record.dat","r");
    newrec = fopen("new.dat","w");
    printf("\n Enter the account no of the customer whose info you want to change :\n");
    scanf("%d",&upd.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",&add.acc_no,add.name,&add.dob.mounth,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.mounth,&add.deposit.day,&add.deposit.year) != EOF)
    {
        if(add.acc_no == upd.acc_no)
        {
            test = 1;
            printf("\n Wich information you want to change ?? :\n1.Address \n2.Phone \n\n Enter your choice :");
            scanf("%d",&choice);
            system("cls");
            if (choice == 1)
            {
                printf("Enter the Address :");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %.2lf %s %.2f %d/%d/%d \n",add.acc_no,add.name,add.dob.mounth,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.mounth,add.deposit.day,add.deposit.year);
                system("cls");
                printf("changes saved !\n");
            }
            else if (choice == 2)
            {
                
                printf("Enter the new phone number : ");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",add.acc_no,add.name,add.dob.mounth,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.mounth,add.deposit.day,add.deposit.year);
                system("cls");
                printf("changes saved !\n");
            }
            else
            {
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",add.acc_no,add.name,add.dob.mounth,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.mounth,add.deposit.day,add.deposit.year);
            }
            
            
        }
        fclose(old);
        fclose(newrec);
        printf("Removing old data ... \n");
        Sleep(5000);
        remove("record.dat");
        printf("Upload the new data\n");
        Sleep(5000);
        rename("new.dat","record.dat");
        printf("\t\tSuccessfuly !!!\n");

        if (test != 1)
        {
            system("cls");
            printf("\n record not found !!!");
            edit_invalid :
            printf("\n Enter 0 to try agin 1 to return to the main menu and 2 to Exit :");
            scanf("%d",&main_exit);
            system("cls");
            if (main_exit == 1)
            {
                menu();
            }
            else if (main_exit == 2)
            {
                closed();
            }
            else if (main_exit == 0)
            {
               edit();
            }
            else {
                printf("\n Invalid Input !!!");
                goto edit_invalid;
            }
            
            
            
        }
        else 
        {
            printf("\n\n\n Enter 1 to go to the main menu and 0 to Exit :");
            scanf("%d",&main_exit);
            system("cls");
            if (main_exit == 1)
            {
                menu();
            }
            else {
                closed();
            }
            

        }
        
    }
}

void transcat() {
    int choice,test = 0;
    FILE *old,*newrec;
    old = fopen("record.dat","r");
    newrec = fopen("new.dat","w");
    if (old == NULL || newrec == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter the account no of the costomer :");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",&add.acc_no,add.name,&add.dob.mounth,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.mounth,&add.deposit.day,&add.deposit.year) != EOF)
    {
        printf("add:%d\n",add.acc_no);
        printf("tran:%d\n",transaction.acc_no);
        printf("%s\n",add.acc_type);
        if (add.acc_no == transaction.acc_no)
        {
            
            test = 1;
            printf("\n\n You are in the account of %s\n",add.name);
            if (strcmp(add.acc_type,"Fixed1") == 0 || strcmp(add.acc_type,"Fixed2") == 0 || strcmp(add.acc_type,"Fixed3") == 0)
            {
                printf("you cannot deposit or withdrow cash in fixed account\n");
                Sleep(10000);
                system("cls");
                menu();
                fclose(old);
                fclose(newrec);
                return;
            }
            Input_invalid:
            printf("\n\n Do you want to \n1.deposit \n2.withdraw ?? \n3.return to menu \n4.exit \nEnter you choice :");
            scanf("%d",&choice);
            if (choice == 1)
            {
                printf("Enter the amount you want to deposit :$");
                scanf("%f",&transaction.amt);
                add.amt += transaction.amt;
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",add.acc_no,add.name,add.dob.mounth,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.mounth,add.deposit.day,add.deposit.year);
                printf("\n\n Deposited successfully !!");
                
            }
            else if (choice == 2)
            {
                printf("\n Enter the amount you want to withdraw : $");
                scanf("%f",&transaction.amt);
                if (transaction.amt > add.amt) {
                    printf("Insufficient funds!\n");
                    goto Input_invalid;
                }
                add.amt -= transaction.amt;
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",add.acc_no,add.name,add.dob.mounth,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.mounth,add.deposit.day,add.deposit.year);
                printf("\n\n Withdraw successfully !!");
            }
            else if (choice == 3)
            {
                menu();
                fclose(old);
                fclose(newrec);
                return;

            }
            else if (choice == 4)
            {
                closed();
                fclose(old);
                fclose(newrec);
                return;
            }
            else {
                printf("Invalide Input \n");
                goto Input_invalid;
            }
            
        }
        else
        {
                
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",add.acc_no,add.name,add.dob.mounth,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.mounth,add.deposit.day,add.deposit.year);
                
        }
        
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if (test != 1)
    {
        printf("\n\n Record not found !!");
        transcat_invalid:
        printf("\n\n\n Enter 0 or try agin ,1 to return to the main menu and 2 to Exit :");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit == 0)
        {
            transcat();
        }
        else if (main_exit == 1)
        {
            
            menu();
            
        }
        else if (main_exit == 2)
        {
            closed();
        }
        else{
            printf("\n Invalid !!");
            goto transcat_invalid;
        }
        
        
        
    }
    else
    {
        printf("\n Enter 1 to go to the main menu and 0 to Exit :");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit == 1)
        {
            menu();
        }
        else if (main_exit == 0)
        {
            closed();
        }
        
    }
    
}
//23:06

void see()
{
    FILE *ptr;
    int test = 0,rate;
    int choice;
    float time;
    float intrst;
    ptr = fopen("record.dat","r");
    if (ptr == NULL) {
        printf("Error: Could not open file!\n");
        return;
    }
    printf("Do you want to check by \n1.Account no \n2.Name \n3.Return to menu \n4.Exit \n Enter your choice :");
    scanf("%d",&choice);
    if (choice == 1)
    {
        printf("Enter the account number : ");
        scanf("%d",&check.acc_no);

    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",&add.acc_no,add.name,&add.dob.mounth,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.mounth,&add.deposit.day,&add.deposit.year) != EOF)
    {
        if (add.acc_no == check.acc_no)
        {
            system("cls");
            fordelay(1);
            test = 1;
            printf("\n Account no . : %d \n Name : %s \n DOB : %d/%d/%d \n Age :%d \n Address : %s \n Citizenship No : %s \n Phone number : %.0lf \n Type of Account : %s \n Amount deposited : $ %.2f \n Date of Deposit : %d/%d/%d \n\n",add.acc_no,add.name,add.dob.mounth,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.mounth,add.deposit.day,add.deposit.year);
            
            if (strcmp(add.acc_type,"Fixed1") == 0 || strcmp(add.acc_type,"Fixed2") == 0 || strcmp(add.acc_type,"Fixed3") == 0)
            {
                printf("\n\n You will get no interest");
            }
            break;
            
        }
        
    }
    }
    //26:19
    else if (choice == 2)
    {
        printf("Enter the name : ");
        scanf("%s",check.name);
    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",&add.acc_no,add.name,&add.dob.mounth,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.mounth,&add.deposit.day,&add.deposit.year) != EOF)
        {
            if (strcmp(add.name,check.name) == 0)
            {
                system("cls");
                test = 1;
                printf("\n Account no . : %d \n Name : %s \n DOB : %d/%d/%d \n Age :%d \nAddress : %s \n Citizenship No : %s \n Phone number : %.0lf \n Type of Account : %s \n Amount deposited : $ %.2f \n Date of Deposit : %d/%d/%d \n\n",add.acc_no,add.name,add.dob.mounth,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.mounth,add.deposit.day,add.deposit.year);

            if (strcmp(add.acc_type,"Fixed1") == 0 || strcmp(add.acc_type,"Fixed2") == 0 || strcmp(add.acc_type,"Fixed3") == 0)
            {
                printf("\n\n You will get no interest");
            }
            break;
            }
        }
    }
    else if (choice == 3)
    {
        menu();
    }
    else if (choice == 4)
    {
        closed();
    }
    fclose(ptr);
    if (test != 1 )
    {
        system("cls");
        printf("\n Record not found !!");
        see_invalid :
        printf("\n Enter 0 to try agin, 1 to return to the maine menu and 2 to Exit : \n");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit == 1)
        {
            menu();
        }
        else if (main_exit == 2)
        {
            closed();
        }
        else if (main_exit == 0)
        {
            see();
        }
        else 
        {
            system("cls");
            printf("\n Invalid !!");
            goto see_invalid;
        }
        
        
        
    }
    else
    {
        printf("\n Enter 1 to go to the main menu and 0 to Exit : \n");
        scanf("%d",&main_exit);
        if (main_exit == 1)
        {
            system("cls");
            menu();
        }
        else if(main_exit == 0){
            system("cls");
            closed();
        }
        
    }
    
    
    
    
}

//28:49

void erase() 
{
    FILE *old,*newrec;
    int test = 0;
    old = fopen("record.dat","r");
    newrec = fopen("new.dat","w");
    printf("Enter the account no of the customer you want to delete : ");
    scanf("%d",&rem.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",&add.acc_no,add.name,&add.dob.mounth,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.mounth,&add.deposit.day,&add.deposit.year) != EOF)
    {
        if (add.acc_no != rem.acc_no)
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",add.acc_no,add.name,add.dob.mounth,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.mounth,add.deposit.day,add.deposit.year);
            break;
        }
        else
        {
            test++;
            printf("\n Record deleted successfully ! \n\n");
            break;
        }
        
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if (test == 0)
    {
        printf("\n record not found !! \n\n");
        erase_invalid :
        printf("\n enter 0 to try agin , 1 to return to main menu and 2 to Exit : ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit == 1)
        {
            menu();
        }
        else if (main_exit == 2)
        {
            closed();
        }
        else if (main_exit == 0)
        {
            erase();
        }
        else 
        {
            printf("\n Invalid !! \n");
            goto erase_invalid;
        }
    }
    else
    {
        printf("\n Enter 1 to go to the main menu and 0 to Exit : ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit == 1)
        {
            menu();
        }
        else if (main_exit == 2)
        {
            closed();
        }

    }
    

}
void view_list() {
    FILE *view;
    view = fopen("record.dat","r");
    int test = 0;
    system("cls");

    printf("\n ACC.no \t Name \t\t Address \t Phone \n");
    while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",&add.acc_no,add.name,&add.dob.mounth,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.mounth,&add.deposit.day,&add.deposit.year) != EOF)
    
    {
        printf("\n%6d\t\t %s\t\t %s\t\t %.0lf",add.acc_no,add.name,add.address,add.phone);
        test++;
        
    }
    fclose(view);
    if (test == 0)
    {
        system("cls");
        printf("\n NO RECORDS !!\n");

    }
    view_list_invalid:
    printf("\n\n Enter 1 to go to the main menu and 0 to Exit :");
    scanf("%d",&main_exit);
    system("cls");
        if (main_exit == 1)
        {
            menu();
        }
        else if (main_exit == 0)
        {
            closed();
        }
        else{
            printf("\n Invalid ! \n");
            goto view_list_invalid;
        }

}

void closed() {
    system("cls");
    printf("\t\t***********************************************\n");
    printf("\t\t*                                             *\n");
    printf("\t\t*               Good, Bye!!!!!!!!!!!          *\n");
    printf("\t\t*                                             *\n");
    printf("\t\t***********************************************\n");
    Sleep(3000);
    

}