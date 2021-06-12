#include <stdio.h>

void printRow(int table[9][9], int rowNum);
void printTable(int table[9][9]);
void putCell(int *cell, int value);

void printRow(int table[9][9], int rowNum){
    for (int counter = 0; counter < 9; counter++){
        printf("%d ", table[rowNum][counter]);
    }
    printf("\n");
}

void printTable(int table[9][9]){
    for (int rowNum = 0; rowNum < 9; rowNum++){
        printRow(table, rowNum);
    }
    printf("\n");
}

void putCell(int *cell, int value){
    *cell = value;
}

void completeLine(int table[9][9], int rowOrColumn, int num);

void completeLine(int table[9][9], int rowOrColumn, int num){
    if (rowOrColumn == 0){
        int emptyCells = 0;
        int sumOfLine = 0;
        int indexOfEmptyCell = 999;
        for (int column = 0; column < 9; column++){
            if (table[num][column] == 0){
                emptyCells++;
                indexOfEmptyCell = column;
            }
            sumOfLine += table[num][column];
        }
        if (emptyCells == 1){
            // table[num][indexOfEmptyCell] = 45 - sumOfLine;
            putCell(&table[num][indexOfEmptyCell], 45 - sumOfLine);
        }
    }
}

int main(int argc, char *argv[]){
    int table[9][9] = {
        {0, 0, 0, 0, 0, 0, 3, 0, 6},
        {1, 0, 0, 9, 0, 0, 0, 7, 8},
        {0, 0, 0, 0, 0, 2, 0, 0, 0},
        {8, 6, 5, 2, 7, 1, 0, 9, 3},
        {0, 0, 0, 4, 6, 5, 7, 0, 2},
        {0, 0, 4, 0, 9, 3, 0, 5, 0},
        {0, 2, 8, 3, 4, 0, 1, 0, 0},
        {3, 9, 6, 1, 5, 8, 0, 4, 7},
        {0, 1, 7, 6, 2, 9, 8, 0, 5},
    };

    printTable(table);
    completeLine(table, 0, 3);
    completeLine(table, 0, 7);
    printTable(table);

    return 0;
}
