#include <unistd.h>
#include <stdio.h>


int main() {
    int i;
    int ans1,ans2,ans3,ans4,ans5;
    int point1,point2,point3,point4,point5,point6,point7,point8,point9,point10;
    int point01,point02,point03,point04,point05,point06,point07,point08,point09,point010;
    int total1,total2,total3;

    printf("Welcome to the game\r\n");

    printf("> Press 7 to start the game\n");
    printf("> Press 0 to quit the game\n");


    scanf("%d",&i);
    if (i==7){
        printf("The game has started\r\n");
        printf("\n");
    }else if (i==0){
        printf("The game has ended\r\n");
        printf("\n");

    }else {
        printf("Invalid\r\n");
        printf("\n");

    }

    if(i==7){

        //11111111111111111111111111111111111
        printf("1)_ Wich one is the first search engine in internet?\r\n");
        printf("1)_Google\n");
        printf("2)_Archie\n");
        printf("3)_Wais\n");
        printf("4)_Altavista\n");

        printf("Enter Your Answer : ");
        scanf("%d",&ans1);
        printf("\n");
        if (ans1 == 2) {
            printf("Correct Answer\n");
            point1 = 5;
            printf("You have scored %d point\n",point1);
        }else{
            printf("Wrong Answer\n");
            point01 = 0;
            printf("You have scored %d point\n",point01);
            
        }
        printf("\n");
        //2222222222222222222222222222222222222

        printf("2)_Wich one is the first web browzer invented in 1990?\r\n");
        printf("1)_Internet Explorer\n");
        printf("2)_Mosaic\n");
        printf("3)_Mozilla\n");
        printf("4)_Nexus\n");

        printf("Enter Your Answer : ");
        scanf("%d",&ans2);
        printf("\n");


        if (ans2 == 4) {
            printf("Correct Answer\n");
            point2 = 5;
            printf("You have scored %d point\n",point2);
        }else {
             printf("Wrong Answer\n");
             point02 = 0;
             printf("You have scored %d point\n",point02);
        }
        printf("\n");

        //3333333333333333333333333333333
        printf("3)_ First computer virus is know as ?\r\n");
        printf("1)_Rabbit\n");
        printf("2)_Creeper Virus\n");
        printf("3)_Elk Cloner\n");
        printf("4)_SCA Virus\n");

        printf("Enter Your Answer : ");
        scanf("%d",&ans3);
        printf("\n");


        if (ans3 == 2) {
            printf("Correct Answer\n");
            point3 = 5;
            printf("You have scored %d point\n",point3);
        }else {
             printf("Wrong Answer\n");
             point03 = 0;
             printf("You have scored %d point\n",point03);
        }
        printf("\n");

        //44444444444444444444444444444444444
        printf("4)_Firwall in computer is used for?\r\n");
        printf("1)_Security\n");
        printf("2)_Data Transmission\n");
        printf("3)_Monitoring\n");
        printf("4)_Authentication\n");

        printf("Enter Your Answer : ");
        scanf("%d",&ans4);
        printf("\n");


        if (ans4 == 1) {
            printf("Correct Answer\n");
            point4 = 5;
            printf("You have scored %d point\n",point4);
        }else {
             printf("Wrong Answer\n");
             point04 = 0;
             printf("You have scored %d point\n",point04);
        }
        printf("\n");

        //555555555555555555555555555
        printf("5)_Which of the following is not a database management software?\r\n");
        printf("1)_Mysql\n");
        printf("2)_Oracle\n");
        printf("3)_Cobal\n");
        printf("4)_Sybase\n");

        printf("Enter Your Answer : ");
        scanf("%d",&ans5);
        printf("\n");


        if (ans5 == 3) {
            printf("Correct Answer\n");
            point5 = 5;
            printf("You have scored %d point\n",point5);
        }else {
             printf("Wrong Answer\n");
             point05 = 0;
             printf("You have scored %d point\n",point05);
        }
        printf("\n");

    }
    total1 = point1 + point2 + point3 + point4 + point5;
    if (total1 >= 15 ){
        printf("Congrate You Sucess , Your score is : %d/25",total1);
        printf("\n");
        printf("  _____                    _    _____\n");
        printf(" / ____|  ___    ___      | |  / ____|\n");
        printf("| |  __  / _ \\  / _ \\   __| | | |  __    __ _   _ __ ___    ___ \n");
        printf("| | |_ || (_) || (_) | / _` | | | |_ |  / _` | | '_ ` _ \\  / _ \\");
        printf("\n");
        printf("| |__| | \\___/  \\___/ | (_| | | |__| | | (_| | | | | | | ||  __/\n");
        printf(" \\_____|               \\__,_|  \\_____|  \\__,_| |_| |_| |_| \\___|\n");
    }else{
        printf("You lose : %d/25",total1);
    }
    

    
}

