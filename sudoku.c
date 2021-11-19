#include <stdio.h>
#include <stdlib.h>
#define ROW 0
#define COLUMN 1
#define VALID 1
#define INVALID 0

void printRow(int table[9][9], int rowNum);
void printTable(int table[9][9]);
void putCell(int *cell, int value);
void completeLine(int table[9][9], int rowOrColumn, int num);
void completeSubTable(int table[9][9], int subRow, int subColumn);
int checkLineValidity(int table[9][9], int rowOrColumn, int lineNum, int num);
int checkSubtableValidity(int table[9][9], int row, int column, int num);
void completeLineWith2Cells(int table[9][9], int rowOrColumn, int num);

// テーブルの1行を出力する
void printRow(int table[9][9], int rowNum){
    for (int counter = 0; counter < 9; counter++){
        printf("%d ", table[rowNum][counter]);
    }
    printf("\n");
}

// テーブル全体を出力する
void printTable(int table[9][9]){
    for (int rowNum = 0; rowNum < 9; rowNum++){
        printRow(table, rowNum);
    }
    printf("\n");
}

// セルに値を代表する
void putCell(int *cell, int value){
    *cell = value;
}

// 1行or1列に空きセルが1つの時に値を埋める
void completeLine(int table[9][9], int rowOrColumn, int num){
    int emptyCells = 0;
    int sumOfLine = 0;
    int indexOfEmptyCell = -1;
    if (rowOrColumn == ROW){
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
    } else if (rowOrColumn == COLUMN){
        for (int row = 0; row < 9; row++){
            if (table[row][num] == 0){
                emptyCells++;
                indexOfEmptyCell = row;
            }
            sumOfLine += table[row][num];
        }
        if (emptyCells == 1){
            // table[num][indexOfEmptyCell] = 45 - sumOfLine;
            putCell(&table[indexOfEmptyCell][num], 45 - sumOfLine);
        }
    }
}

// サブテーブルに空きセルが1つの時に値を埋める
void completeSubTable(int table[9][9], int subRow, int subColumn){
    int emptyCells = 0;
    int sumOfSubTable = 0;
    int indexOfEmptyRow = -1;
    int indexOfEmptyColumn = -1;
    for (int row = subRow * 3; row < subRow * 3 + 3; row++){
        for (int column = subColumn * 3; column < subColumn * 3 + 3; column++){
            if (table[row][column] == 0){
                emptyCells++;
                indexOfEmptyRow = row;
                indexOfEmptyColumn = column;
            }
            sumOfSubTable += table[row][column];
        }
    }
    if (emptyCells == 1){
        putCell(&table[indexOfEmptyRow][indexOfEmptyColumn], 45 - sumOfSubTable);
    }
}

int checkLineValidity(int table[9][9], int rowOrColumn, int lineNum, int num){
    int answer = VALID;
    int counter;
    
    if (rowOrColumn == ROW){
        for (counter = 0; counter < 9; counter++){
            if (table[lineNum][counter] == num){
                answer = INVALID;
            }
        }
    } else if (rowOrColumn == COLUMN){
        for (counter = 0; counter < 9; counter++){
            if (table[counter][lineNum] == num){
                answer = INVALID;
            }
        }
    } else{
        answer = INVALID;
    }

    return answer;
}

int checkSubtableValidity(int table[9][9], int row, int column, int num){
    int answer = VALID;
    int subrow;
    int subcolumn;

    for (subrow = (div(row, 3).quot * 3); subrow < (div(row, 3).quot * 3) + 3; subrow++){
        for (subcolumn = (div(column, 3).quot * 3); subcolumn < (div(column, 3).quot * 3) + 3; subcolumn++){
            if (table[subrow][subcolumn] == num){
                answer == INVALID;
            }
        }
    }

    return answer;
}

// 1行or1列に空きセルが2つの時に値を埋める
void completeLineWith2Cells(int table[9][9], int rowOrColumn, int num){
    
    int checkEmptyValues[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int valueOfEmptyCells[2] = {-1, -1};
    int indexOfEmptyCells[2] = {0, 0};
    int numOfEmptyCells = 0;
    int counter = 0;
    
    if (rowOrColumn == ROW){
        for (counter = 0; counter < 9; counter++){
            if (table[num][counter] == 0){
                indexOfEmptyCells[numOfEmptyCells] = counter;
                numOfEmptyCells++;
            }
            else{
                checkEmptyValues[table[num][counter] - 1] = 0;
            }
        }
        
        for (counter = 0; counter < 9; counter++){
            if (checkEmptyValues[counter] != 0){
                valueOfEmptyCells[numOfEmptyCells - 1] = checkEmptyValues[counter];
                numOfEmptyCells--;
            }
        }

        printf("valueOfEmptyCells[2] : %d %d\n", valueOfEmptyCells[0], valueOfEmptyCells[1]);
        printf("indexOfEmptyCells[2] : %d %d\n", indexOfEmptyCells[0], indexOfEmptyCells[1]);
        printf("\n");

        if (checkLineValidity(table, COLUMN, indexOfEmptyCells[0], valueOfEmptyCells[0]) == INVALID || 
            checkSubtableValidity(table, num, indexOfEmptyCells[0], valueOfEmptyCells[0]) == INVALID){
            putCell(&table[num][indexOfEmptyCells[0]], valueOfEmptyCells[1]);
            putCell(&table[num][indexOfEmptyCells[1]], valueOfEmptyCells[0]);
        } else{
            putCell(&table[num][indexOfEmptyCells[0]], valueOfEmptyCells[0]);
            putCell(&table[num][indexOfEmptyCells[1]], valueOfEmptyCells[1]);
        }

    } else if (rowOrColumn == COLUMN){
        for (counter = 0; counter < 9; counter++){
            if (table[counter][num] == 0){
                indexOfEmptyCells[numOfEmptyCells] = counter;
                numOfEmptyCells++;
            }
            else{
                checkEmptyValues[table[counter][num] - 1] = 0;
            }
        }
        
        for (counter = 0; counter < 9; counter++){
            if (checkEmptyValues[counter] != 0){
                valueOfEmptyCells[numOfEmptyCells - 1] = checkEmptyValues[counter];
                numOfEmptyCells--;
            }
        }

        printf("valueOfEmptyCells[2] : %d %d\n", valueOfEmptyCells[0], valueOfEmptyCells[1]);
        printf("indexOfEmptyCells[2] : %d %d\n", indexOfEmptyCells[0], indexOfEmptyCells[1]);
        printf("\n");

        if (checkLineValidity(table, ROW, indexOfEmptyCells[0], valueOfEmptyCells[0]) == INVALID || 
            checkSubtableValidity(table, num, indexOfEmptyCells[0], valueOfEmptyCells[0]) == INVALID){
            putCell(&table[indexOfEmptyCells[0]][num], valueOfEmptyCells[1]);
            putCell(&table[indexOfEmptyCells[1]][num], valueOfEmptyCells[0]);
        } else{
            putCell(&table[indexOfEmptyCells[0]][num], valueOfEmptyCells[0]);
            putCell(&table[indexOfEmptyCells[1]][num], valueOfEmptyCells[1]);
        }

    } else{
        printf("Invalid rowOrColumn!");
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

    completeLine(table, ROW, 3);
    completeLine(table, ROW, 7);
    printTable(table);

    completeSubTable(table, 1, 1);
    completeSubTable(table, 2, 1);
    printTable(table);

    completeLineWith2Cells(table, ROW, 8);

    printTable(table);

    completeLineWith2Cells(table, COLUMN, 5);

    printTable(table);

    return 0;
}
