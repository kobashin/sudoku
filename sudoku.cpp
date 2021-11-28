#include <iostream>
#include <stdlib.h>
using namespace std;
#include "sudoku.h"

void initCandidates(int table[9][9], int fixed[9][9], int candidates[9][9][9]){
    int row;
    int column;
    int index;

    for (row = 0; row < 9; row++){
        for (column = 0; column < 9; column++){
            if (table[row][column] != 0){
                for (index = 0; index < 9; index++){
                    if (table[row][column] != (index + 1)){
                        candidates[row][column][index] = 0;
                    }
                }
                fixed[row][column] = 1;
            }
        }
    }
}

void filterRowCandidates(int row, int column, int table[9][9], int fixed[9][9], int candidates[9][9][9]){
    int columnIndex;

    for (columnIndex = 0; columnIndex < 9; columnIndex++){
        if (columnIndex != row){
            if (candidates[row][columnIndex][table[row][column] - 1] == table[row][column]){
                candidates[row][columnIndex][table[row][column] - 1] = 0;
            }
        }
    }
}

void filterColumnCandidates(int row, int column, int table[9][9], int fixed[9][9], int candidates[9][9][9]){
    int rowIndex;

    for (rowIndex = 0; rowIndex < 9; rowIndex++){
        if (rowIndex != column){
            if (candidates[rowIndex][column][table[row][column] - 1] == table[row][column]){
                candidates[rowIndex][column][table[row][column] - 1] = 0;
            }
        }
    }
}

void filterSubtableCandidates(int row, int column, int table[9][9], int fixed[9][9], int candidates[9][9][9]){
    int rowIndex;
    int columnIndex;

    for (rowIndex = div(row, 3).quot; rowIndex < div(row, 3).quot + 3; rowIndex++){
        for (columnIndex = div(column, 3).quot; columnIndex < div(column, 3).quot + 3; columnIndex++){
            if((rowIndex != row) | (columnIndex != column)){
                if (candidates[rowIndex][columnIndex][table[row][column] - 1] == table[row][column]){
                    candidates[rowIndex][columnIndex][table[row][column] - 1] = 0;
                }
            }
        }
    }
}

void filterCandidates(int table[9][9], int fixed[9][9], int candidates[9][9][9]){
    int row;
    int column;
    int index;

    for (row = 0; row < 9; row++){
        for (column = 0; column < 9; column++){
            if (table[row][column] != 0){
                filterRowCandidates(row, column, table, fixed, candidates);
                filterColumnCandidates(row, column, table, fixed, candidates);
                filterSubtableCandidates(row, column, table, fixed, candidates);
            }
        }
    }
}

int countCandidates(int candidates[9]){
    int counter = 0;
    int index;

    for (index = 0; index < 9; index++){
        if (candidates[index] != 0){
            counter++;
        }
    }

    return counter;
}

void fillTable(int table[9][9], int fixed[9][9], int candidates[9][9][9]){
    int row;
    int column;
    int index;
    int value = -1;

    for (int row = 0; row < 9; row++){
        for (int column = 0; column < 9; column++){
            if ((fixed[row][column] == 0) & (countCandidates(candidates[row][column]) == 1)){
                for (index = 0; index < 9; index++){
                    if (candidates[row][column][index] != 0){
                        value = candidates[row][column][index];
                    }
                }
                table[row][column] = value;
                fixed[row][column] = 1;
            }
        }
    }
}

void SudokuTable::getTable(){
    for (int row = 0; row < 9; row++){
        for (int column = 0; column < 9; column++){
            cout << this->tableInfo.table[row][column] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void SudokuTable::getFixed(){
    for (int row = 0; row < 9; row++){
        for (int column = 0; column < 9; column++){
            cout << this->tableInfo.fixed[row][column] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void SudokuTable::getCandidates(){
    for (int row = 0; row < 9; row++){
        for (int column = 0; column < 9; column++){
            cout << "table[" << row << "][" << column << "] : " 
            << this->tableInfo.candidates[row][column][0]
            << this->tableInfo.candidates[row][column][1]
            << this->tableInfo.candidates[row][column][2]
            << this->tableInfo.candidates[row][column][3]
            << this->tableInfo.candidates[row][column][4]
            << this->tableInfo.candidates[row][column][5]
            << this->tableInfo.candidates[row][column][6]
            << this->tableInfo.candidates[row][column][7]
            << this->tableInfo.candidates[row][column][8]
            << endl;
        }
    }
}

void SudokuTable::countFilled(){
    int filled = 0;
    for (int row = 0; row < 9; row++){
        for (int column = 0; column < 9; column++){
            if (this->tableInfo.table[row][column] != 0){
                filled++;
            }
        }
    }
    cout << "filled : " << filled << endl;
}

int main(){
    tableInfo tableinfo = 
    {
        {
            {0, 0, 0, 0, 0, 0, 3, 0, 6},
            {1, 0, 0, 9, 0, 0, 0, 7, 8},
            {0, 0, 0, 0, 0, 2, 0, 0, 0},
            {8, 6, 5, 2, 7, 1, 0, 9, 3},
            {0, 0, 0, 4, 6, 5, 7, 0, 2},
            {0, 0, 4, 0, 9, 3, 0, 5, 0},
            {0, 2, 8, 3, 4, 0, 1, 0, 0},
            {3, 9, 6, 1, 5, 8, 0, 4, 7},
            {0, 1, 7, 6, 2, 9, 8, 0, 5}
        },

        {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}
        },

        {
            {
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9}
            },
            {
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9}
            },
            {
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9}
            },
            {
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9}
            },
            {
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9}
            },
            {
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9}
            },
            {
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9}
            },
            {
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9}
            },
            {
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9}
            }
        }
    };

    SudokuTable testTable;

    testTable.tableInfo = tableinfo;

    initCandidates(testTable.tableInfo.table, testTable.tableInfo.fixed, testTable.tableInfo.candidates);
    
    filterCandidates(testTable.tableInfo.table, testTable.tableInfo.fixed, testTable.tableInfo.candidates);
    fillTable(testTable.tableInfo.table, testTable.tableInfo.fixed, testTable.tableInfo.candidates);
    testTable.countFilled();

    filterCandidates(testTable.tableInfo.table, testTable.tableInfo.fixed, testTable.tableInfo.candidates);
    fillTable(testTable.tableInfo.table, testTable.tableInfo.fixed, testTable.tableInfo.candidates);
    testTable.countFilled();

    filterCandidates(testTable.tableInfo.table, testTable.tableInfo.fixed, testTable.tableInfo.candidates);
    fillTable(testTable.tableInfo.table, testTable.tableInfo.fixed, testTable.tableInfo.candidates);
    testTable.countFilled();

    filterCandidates(testTable.tableInfo.table, testTable.tableInfo.fixed, testTable.tableInfo.candidates);
    fillTable(testTable.tableInfo.table, testTable.tableInfo.fixed, testTable.tableInfo.candidates);
    testTable.countFilled();

    filterCandidates(testTable.tableInfo.table, testTable.tableInfo.fixed, testTable.tableInfo.candidates);
    fillTable(testTable.tableInfo.table, testTable.tableInfo.fixed, testTable.tableInfo.candidates);
    testTable.countFilled();

    filterCandidates(testTable.tableInfo.table, testTable.tableInfo.fixed, testTable.tableInfo.candidates);
    fillTable(testTable.tableInfo.table, testTable.tableInfo.fixed, testTable.tableInfo.candidates);
    testTable.countFilled();

    testTable.getTable();
    /*
    testTable.getFixed();
    testTable.getCandidates();
    */

    return 0;
}
