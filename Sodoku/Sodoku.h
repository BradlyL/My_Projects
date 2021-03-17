#include <cstdlib>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

class Sodoku{
    private:
    ifstream board;
    public:
    void create_board();
    void add_value(int add_val, int row, int col);
    void rem_value(int row, int col);
    int mat[9][9];
};


//Function to create board

void Sodoku::create_board() {
    int val;
    board.open("board.txt");

    for (int i=0; i<9; i++) {
        cout << endl;  
        for (int j=0; j<9; j++) {
            board >> mat[i][j];
            cout << mat[i][j] << "  ";
        }
    }

    cout << endl << endl;

}

//Function to check answer

//Function to add values
void Sodoku::add_value(int add_val, int row, int col) {
    int tmp;
    mat[row][col] = add_val;

    for (int i=0; i<9; i++) {
        cout << endl;  
        for (int j=0; j<9; j++) {
            cout << mat[i][j] << "  ";
        }
    }

    cout << endl << "Added value: " << add_val << " at " << row << "x" << col << endl;

}
//Function to remove values

void Sodoku::rem_value(int row, int col) {
    int tmp;
    tmp = mat[row][col];
    mat[row][col] = 0;

    for (int i=0; i<9; i++) {
        cout << endl;  
        for (int j=0; j<9; j++) {
            cout << mat[i][j] << "  ";
        }
    }
    cout << endl << "Removed value: "<< tmp << " at " << row << "x" << col << endl;

}