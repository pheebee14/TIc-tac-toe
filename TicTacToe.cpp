#include <iostream>

void fill_board(char array[][3], int rows, int columns);
void print_board(char array[][3], int rows, int columns);
void player_move(char array[][3], int rows, int columns);
bool isValid(char array[][3], int rows, int columns, int row_input, int column_input);
void computer_move(char array[][3], int rows, int columns);

int main () {
    std::string start_game;
    char board[3][3];
    int rows = sizeof(board)/sizeof(board[0]);
    int columns = sizeof(board[0])/sizeof(board[0][0]);

    std::cout << "TIC TAC TOE" << std::endl;
    std::cout << "****************" << std::endl;
    do{
        std::cout << "START GAME? (OK): ";
        std::cin >> start_game;
    }while(start_game != "OK");

    fill_board(board, rows, columns);
    print_board(board, rows, columns);

    do{
        player_move(board, rows, columns);
        std::cout << "\n" << "***********************" << std::endl;
        std::cout << "COmputer move!: " << "\n" << std::endl;
        computer_move(board, rows, columns);
    }while(true);

    /*
    While true is a placeholder for now. Change accordingly based on winner, all boxes filled? as such.
    */

    return 0;
}

void fill_board(char array[][3], int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            array[i][j] = ' ';
        }
    }
}

void print_board(char array[][3], int rows, int columns){
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << array[0][0] << " | " << array[0][1] << " | " << array[0][2] << " " << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << array[1][0] << " | " << array[1][1] << " | " << array[1][2] << " " << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << array[2][0] << " | " << array[2][1] << " | " << array[2][2] << " " << std::endl;
    std::cout << "   |   |   " << std::endl;
}

void player_move(char array[][3], int rows, int columns){
    int row;
    int column;

    do{
        std::cout << "Your move! Enter row: ";
        std::cin >> row;
        std::cout << "Enter column: ";
        std::cin >> column;
    }while(row > rows || column > columns);

    isValid(array, rows, columns, row - 1, column - 1);
    print_board(array, rows, columns);

}

void computer_move(char array[][3], int rows, int columns){
    srand(0);

    int random_row = rand() % 3;
    int random_column = rand() % 3;
    bool satisfied = false;

    do {
        if (array[random_row][random_column] != 'X' && array[random_row][random_column] != 'O'){
            array[random_row][random_column] == 'X';
            satisfied = true;

        } else {
            random_row = rand() % 3;
            random_column = rand() % 3;
        }
    }while(satisfied == false);

    print_board(array, rows, columns);
}

bool isValid(char array[][3], int rows, int columns, int row_input, int column_input){
    if (array[row_input][column_input] != 'X' && array[row_input][column_input] != 'O'){
        array[row_input][column_input] = 'O';
    } else {
        std::cout << "Position is already taken!" << std::endl;
        return false;
    }

    return true;
}