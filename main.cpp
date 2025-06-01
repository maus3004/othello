#include <iostream>
using namespace std;

char EMPTY = 'o', BLACK = 'x', WHITE = '+';
// unfinished.. find out if using class is the right way

class BOARD {
    public:
        // board size
        int rows, cols;

        // create new board
        // making it so that board size can be altered
        char** initBoard(int rows, int cols){
            // allocating memory for rows
            char** board = new char*[rows];

            // allocating memory for columns in each row
            for (int i = 0; i < rows; i++) {
                board[i] = new char[cols];
            }

            // initializing empty board
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    board[i][j] = EMPTY;
                }
            }

            return board;
        }

        // fixing memory leak
        void delBoard(char** board, int rows){
            for(int i = 0; i < rows; i++){
                delete [] board[i];
            }

            delete [] board;
        }

        void printBoard(char** board){

        }
};


// check isFlippable


int main() {
    BOARD board;

    int rows = 8, cols = 8;

    char** mainBoard = board.initBoard(rows, cols);
    board.printBoard(mainBoard);
    board.delBoard(mainBoard, rows);
    return 0;
}


// 01 02 03 04 05 06 07 08
// 09 10 11 12 13 14 15 16
// 17 18 19 20 21 22 23 24
// 25 26 27 28 29 30 31 32
// 33 34 35 36 37 38 39 40
// 41 42 43 44 45 46 47 48
// 49 50 51 52 53 54 55 56
// 57 58 59 60 61 62 63 64