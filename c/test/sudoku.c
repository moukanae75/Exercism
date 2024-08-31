#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

bool Valid(int board[9][9], int num, int i, int j);
bool Check(int board[9][9]);
bool storPosition(int i,int j);
int Board[9][9] = {{0, 9, 6, 0, 4, 0, 0, 0, 1},
                   {1, 0, 0, 0, 6, 0, 0, 0, 4},
                   {5, 0, 4, 8, 1, 0, 3, 9, 0},
                   {0, 0, 7, 9, 5, 0, 0, 4, 3},
                   {0, 3, 0, 0, 8, 0, 0, 0, 0},
                   {4, 0, 5, 0, 2, 3, 0, 1, 8},
                   {0, 1, 0, 6, 3, 0, 0, 5, 9},
                   {0, 5, 9, 0, 7, 0, 8, 3, 0},
                   {0, 0, 3, 5, 9, 0, 0, 0, 7}};
bool storPosition(int i,int j) {
    int board[9][9] = {{0, 9, 6, 0, 4, 0, 0, 0, 1},
                       {1, 0, 0, 0, 6, 0, 0, 0, 4},
                       {5, 0, 4, 8, 1, 0, 3, 9, 0},
                       {0, 0, 7, 9, 5, 0, 0, 4, 3},
                       {0, 3, 0, 0, 8, 0, 0, 0, 0},
                       {4, 0, 5, 0, 2, 3, 0, 1, 8},
                       {0, 1, 0, 6, 3, 0, 0, 5, 9},
                       {0, 5, 9, 0, 7, 0, 8, 3, 0},
                       {0, 0, 3, 5, 9, 0, 0, 0, 7}};
   
    for (int a = 0; a < 9; a++) {
        for (int b = 0; b < 9; b++) {
            if (board[a][b] != 0 && a == i && b == j)
            return true;
            
        }
                            
    }
    return false;
}

int main() {
    

    if (Check(Board)) {
        system("cls");
        printf("The result is : \n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if ( storPosition(i,j)) {
                    printf("\033[1;31m%d \033[0m", Board[i][j]);
                }else {
                printf("%d ", Board[i][j]);
                }
                _sleep(100);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }
    _sleep(10000);
    return 0;
}

bool Check(int board[9][9]) {
    int i;
    int j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                system("cls");
                        for (int a = 0; a < 9; a++) {
                            for (int b = 0; b < 9; b++) {
                                if ( storPosition(a,b)) {
                                    printf("\033[1;31m%d \033[0m", Board[a][b]);
                                }else {
                                    printf("%d ", Board[a][b]);
                                }
                                
                                
                            }
                            printf("\n");
                        }
                        _sleep(1000);
                for (int num = 1; num <= 9; num++) {
                        
                    if (Valid(board, num, i, j)) {

                        board[i][j] = num;
                        
                        
                        
                        
                        
                        if (Check(board)) {
                            
                            return true;
                        }
                        board[i][j] = 0;
                    }
                    
                }
                return false;
                
            }
            
        }
         
    }
    return true;
}

bool Valid(int Board[9][9], int num, int row, int col) {
    // Check row
    for (int i = 0; i < 9; i++) {
        if (Board[row][i] == num) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < 9; i++) {
        if (Board[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 subgrid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (Board[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}
