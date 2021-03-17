#include <cstdlib>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

//Only needs a way to check 3x3

class Sodoku{
    private:
    ifstream board;

    public:
    void create_board();
    int add_value(int add_val, int row, int col);
    void rem_value(int row, int col);
    bool check_puzzle(int matrix[9][9]);
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

bool Sodoku::check_puzzle(int matrix[9][9]) {
    bool check = false;
    int total = 0;
    int solved = 405;

    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            total += mat[i][j];
        }
    }

    if (total == solved) {
        check = true;
    }

    return check;
}

//Function to add values
int Sodoku::add_value(int add_val, int row, int col) {
    int tmp;

    //Checks range of input value
    if (add_val > 9 | add_val <=0) {
        cout << "Added value out of range. Try again";
        return 0;
    }

    //Check row
    for (int i=row; i<=row; i++) {
        for (int j=0; j<9; j++) {
            if (add_val == mat[i][j]) {
                cout << "Value found within row. Try again.";
                return 0;
            }
        }
    }

    //Check col
    for (int i=0; i<9; i++) {
        for (int j=col; j<=col; j++) {
            if (add_val == mat[i][j]) {
                cout << "Value found within column. Try again.";
                return 0;
            }
        }
    }
    
    //9x9
    /*
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
        }
    }*/

    //Check to see if value was in original board.
    if (mat[row][col] != 0){
        cout << "Static value. Try again.";
        return 0;
    }

    mat[row][col] = add_val;
    
    for (int i=0; i<9; i++) {
        cout << endl;  
        for (int j=0; j<9; j++) {
            cout << mat[i][j] << "  ";
        }
    }

    cout << endl << endl << "Added value: " << add_val << " at " << row << "x" << col << endl;


    //Solution check, only returns true if total values = 405
    bool check_sol = check_puzzle(mat);
    if (check_sol == true) {
        cout << "Congratulations, you have solved the sodoku.";
    }

    return 0;

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