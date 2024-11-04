#include <stdio.h>
//checking if someone has won
int has_won(int board[][3]){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1){
            return 1;
        }
        if(board[i][0] == -1 && board[i][1] == -1 && board[i][2] == -1){
            return -1;
        }
        if(board[0][i] == 1 && board[1][i] == 1 && board[2][i]== 1){
            return 1;
        }
        if(board[0][i] == -1 && board[1][i] == -1 && board[2][i]== -1){
            return -1;
        }
    }
        if(board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1){
            return 1;
        }
        if(board[2][0] == 1 && board[1][1] == 1 && board[0][2] == 1){
            return 1;
        }
        if(board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1){
            return -1;
        }
        if(board[2][0] == -1 && board[1][1] == -1 && board[0][2] == -1){
            return -1;
        }
    return 0;
}
//Checking for valid moves and inserting X and O into board
int move(int board[][3], int turn, int row, int column){
    if(row < 0 || row > 2 || column < 0 || column > 2){
        return -1;
    }
    if(board[row][column] != 0){
        return -1;
    }else{
        board[row][column] = turn;
        return 1;
    }
}
//Printing board after every move
void print_board(int board[][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == 1) {
                printf("X");
            }else if (board[i][j] == -1) {
                printf("O");
            }else{
                printf("_");
            }
        }
        printf("\n");
    }
}

int main()
{
    printf("Welcome!\n");
    //Creating an empty board
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int turn = 1;
    //Loop of turns
    while (1){
        print_board(board);
        //Getting and entering user input
        printf("Please enter a move: ");
        char row;
        char column;
        scanf("%c,%c", &row, &column);
        //Making rows and columns align with array
        row --;
        column --;
        //Checking validity
        if(move(board, turn, row, column) == -1){
            printf("Invalid input.\n");
            continue;
        }
        //Checking if anyone won
        int result = has_won(board);
        if(result == 1){
            printf("X has won.");
            break;
        }else if(result == -1){
            printf("Y has won.");
            break;
        }
        //Switching turns
        turn *= -1;
    }
    return 0;
}
