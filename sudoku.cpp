#include <iostream>
using namespace std;
#include "sudoku.h"

void SudokuTable::getTable(){
    /*
    for (int row = 0; row < 9; row++){
        for (int column = 0; column < 9; column++){
            cout << this->table[row][column] << " ";
        }
        cout << "\n";
    }
    */

    cout << this->table << endl;
}

void SudokuTable::getCandidates(){
    cout << this->candidates << endl;
}

int main(){
    SudokuTable testTable;

    testTable.table = 3;
    testTable.candidates = 10;

    testTable.getTable();
    testTable.getCandidates();

    return 0;
}
