{
    printf("Welcome!\n");
    //Creating an empty board
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int turn = 1;
    int draw_check = 0;
    //Loop of turns
    for(int i = 1; i < 50; i++){
        print_board(board);
        //Getting and entering user input
        printf("Please enter a move: ");
        char input_string[100];
        scanf("%s", &input_string);
        //Check if the user wants to quit
        if(input_string[0] == 'q' && input_string[1] == '\0'){
            printf("You have terminated the game");
            break;
        }
        //Check for validity
        if(input_string[1] != ',' || strlen(input_string) != 3){
            printf("Invalid input.\n");
            while (getchar() != '\n'); 
            continue;
        }
        printf(">>> ");
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
            printf("Invalid input.\n");
            while (getchar() != '\n'); 
            continue;
        }
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
