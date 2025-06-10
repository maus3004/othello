#include <iostream>
using namespace std;

// board size
int rows = 8 + 1 + 1, cols = 8 + 1 + 1;

// board pieces
char EMPTY = '*', BLACK = 'X', WHITE = 'O', VALID = '$';



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

bool isValidMove(char** board, int pos_rows, int pos_cols, int gameState){

    if(gameState == 0){
        return false;
    }

    return true;
}

bool isBoardFull(char** board){
    // check if all the squares have been filled
    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            if(board[i][j] == EMPTY){
                return false;
            }
        }
    }
    return true;
}

// there's gotta be a better way to do this
void showValidMoves(char** board, int gameState){
    // player's move, always black
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            switch (gameState) {
                default:
                    break;
                case 0:
                    break;
                case 1:
                    break;
            }
        }
    }
    printBoard(board);
}

void flip(char** board, int row, int col, int gameState){

}

// make player v player first, black always goes first


int main() {
    // making board
    // board size
    // can make board size adjustable in the future

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
                board[i][j] = char(border_counter2); // fills left border
                border_counter2++;
            }
        }
        border_counter1++;
    }

    // filling in corners
    board[0][0] = board[0][9] = board[9][0] = board[9][9] = '#';

    // filling initial positions
    board[4][4] = board[5][5] = BLACK;
    board[5][4] = board[4][5] = WHITE;

    // player goes first, player is black
    // computer is white

    // if gameState is 0, player's turn
    // if gameState is 1, computer's turn
    int gameState = 0;

    while(!isBoardFull(board)){
        switch(gameState) {
            default:
                break;
            case 0:
                cout << "BLACK'S MOVE" << endl;
                break;
            case 1:
                cout << "WHITE'S MOVE" << endl;
                break;
        }


        showValidMoves(board, gameState);

        int pos_rows, pos_cols;
        cout << "Piece row number: ";
        cin >> pos_rows;

        cout << "Piece column number: ";
        cin >> pos_cols;

        if(isValidMove(board, pos_rows, pos_cols, gameState)){

        }

        // flipping turns
        if(gameState == 0) {
            gameState++;
        }
        else{
            gameState--;
        }
    }
    printBoard(board);

    // deleting board from memory
    for(int i = 0; i < rows; i++){
        delete[] board[i];
    }

    delete[] board;

    return 0;
}
