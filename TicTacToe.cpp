#include <iostream>

void fill_board(char array[][3], int rows, int columns);
void print_board(char array[][3], int rows, int columns);
void player_move(char array[][3], int rows, int columns);
bool isValid(char array[][3], int rows, int columns, const int &row_input, const int &column_input);
void computer_move(char array[][3], int rows, int columns);
bool player_wins(char array[][3], int rows, int columns);
bool computer_wins(char array[][3], int rows, int columns);

int main () {
    srand(0);
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
        std::cout << "\n" << "***********************" << std::endl;
        std::cout << "Player move!: " << "\n" << std::endl;
        player_move(board, rows, columns);
        std::cout << "\n" << "***********************" << std::endl;
        std::cout << "Computer move!: " << "\n" << std::endl;
        computer_move(board, rows, columns);
        bool player_win_condition = player_wins(board, rows, columns);
        bool computer_win_condition = computer_wins(board, rows, columns);
        if (player_win_condition == true){
            std::cout << "Player wins!" << std::endl;
            break;
        }
        else if (computer_win_condition == true){
            std::cout << "Computer wins!" << std::endl;
            break;
        }
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

    bool valid = isValid(array, rows, columns, row - 1, column - 1);

    while(valid == false){
        std::cout << "Invalid!" << std::endl;
        std::cout << "Your move! Enter row: ";
        std::cin >> row;
        std::cout << "Enter column: ";
        std::cin >> column;

        valid = isValid(array, rows, columns, row - 1, column - 1);
    }
    print_board(array, rows, columns);

}

void computer_move(char array[][3], int rows, int columns){
    int random_row = rand() % 3;
    int random_column = rand() % 3;
    bool satisfied = false;

    do {
        if (array[random_row][random_column] != 'X' && array[random_row][random_column] != 'O'){
            array[random_row][random_column] = 'X';
            satisfied = true;

        } else {
            random_row = rand() % 3;
            random_column = rand() % 3;
        }
    }while(satisfied == false);

    print_board(array, rows, columns);
}

bool isValid(char array[][3], int rows, int columns, const int &row_input, const int &column_input){
    if (array[row_input][column_input] != 'X' && array[row_input][column_input] != 'O'){
        array[row_input][column_input] = 'O';
        return true;
    }

    return false;
}

bool player_wins(char array[][3], int rows, int columns){

    if (array[0][0] == 'O' && array[1][1] == 'O' && array[2][2] == 'O'){
        return true;
    }
    
    if (array[0][2] == 'O' && array[1][1] == 'O' && array[2][0] == 'O'){
        return true;
    }

    for (int i = 0; i < rows; i++){
        if (array[i][0] == 'O' && array[i][1] == 'O' && array[i][2] == 'O'){
            return true;
        }
    }

    for (int i = 0; i < columns; i++){
        if (array[0][i] == 'O' && array[1][i] == 'O' && array[2][i] == 'O' ){
            return true;
        }
    }

    return false;
}

bool computer_wins(char array[][3], int rows, int columns){
    if (array[0][0] == 'X' && array[1][1] == 'X' && array[2][2] == 'X'){
        return true;
    }
    
    if (array[0][2] == 'X' && array[1][1] == 'X' && array[2][0] == 'X'){
        return true;
    }

    for (int i = 0; i < rows; i++){
        if (array[i][0] == 'X' && array[i][1] == 'X' && array[i][2] == 'X'){
            return true;
        }
    }

    for (int i = 0; i < columns; i++){
        if (array[0][i] == 'X' && array[1][i] == 'X' && array[2][i] == 'X'){
            return true;
        }
    }

    return false;
}
