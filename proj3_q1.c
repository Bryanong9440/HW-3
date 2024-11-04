#include <stdio.h>

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
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int turn = 1;
    while (1){
        print_board(board);
        printf("Please enter a move: ");
        int row;
        int column;
        scanf("%i,%i", &row, &column);
        row --;
        column --;
        if(move(board, turn, row, column) == -1){
            printf("Invalid input.\n");
            continue;
        }
        int result = has_won(board);
        if(result == 1){
            printf("X has won.");
            break;
        }else if(result == -1){
            printf("Y has won.");
            break;
        }
        turn *= -1;
    }
    return 0;
}
