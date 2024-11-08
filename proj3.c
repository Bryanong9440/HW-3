#include <stdio.h>
#include <string.h>
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
    print_board(board);
    int turn = 1;
    int draw_check = 0;
    //Loop of turns
    for(int i = 1; i < 50; i++){
        //Getting and entering user input
        printf("Please enter a move: \n");
        char input_string[100];
        scanf("%s", &input_string);
        //Check if the user wants to quit
        if(input_string[0] == 'q' && input_string[1] == '\0'){
            printf(">>>\n");
            break;
        }
        //Check for validity
        if(input_string[1] != ',' || strlen(input_string) != 3){
            printf(">>> Invalid input.\n");
            while (getchar() != '\n'); 
            continue;
        }
        int row;
        int column;
        //Getting the numbers for rows and columns
        row = input_string[0] - 48;
        column = input_string[2] - 48;
        //Making rows and columns align with array
        row --;
        column --;
        //Checking validity
        if(move(board, turn, row, column) == -1){
            printf(">>> Invalid input.\n");
            while (getchar() != '\n'); 
            continue;
        }
        printf(">>> ");
        print_board(board);
        //Checking if anyone won
        int result = has_won(board);
        if(result == 1){
            print_board(board);
            printf("X has won.");
            break;
        }else if(result == -1){
            print_board(board);
            printf("O has won.");
            break;
        }
        //Switching turns
        turn *= -1;
        //Draw check
        draw_check ++;
        if(draw_check == 9){
            printf("It's a draw.\n");
            break;
        }
    }
    return 0;
}
