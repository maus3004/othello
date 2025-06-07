#include <iostream>
using namespace std;

int rows = 8 + 1 + 1, cols = 8 + 1 + 1;

// for future reference, char** initBoard() should be looked into...

// prints the board
void printBoard(char** board){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << board[i][j] << "   ";
        }
        cout << endl;
    }
}


// check isValidMove, show validMoves

// make player v player first, black always goes first


int main() {
    // making board
    // board size
    // can make board size adjustable in the future

    // board pieces
    char EMPTY = '*', BLACK = 'X', WHITE = 'O';

    // create a board
    char** board = new char*[rows];

    // allocating memory for columns in each row
    for (int i = 0; i < rows; i++) {
        board[i] = new char[cols];
    }

    // initializing empty board
    int border_counter1 = 49, border_counter2 = 49; // char(49) returns 1
    for(int i = 1; i < rows; i++){
        // fill the left and top border
        board[i][0] = board[0][i] = char(border_counter1);

        // fill the right and bottom border
        for(int j = 1; j < cols; j++){
            board[i][j] = EMPTY;
            if(j == cols - 1){
                board[i][j] = char(border_counter1); // fills right border
            }
            if(i == rows - 1){
                board[i][j] = char(border_counter2);
                border_counter2++;
            }
        }
        border_counter1++;
    }

    board[0][0] = board[0][9] = board[9][0] = board[9][9] = '#';
    // have to switch in case
    board[4][4] = board[5][5] = WHITE;
    board[5][4] = board[4][5] = BLACK;

    printBoard(board);

    // deleting board from memory
    for(int i = 0; i < rows; i++){
        delete[] board[i];
    }

    delete[] board;

    return 0;
}
