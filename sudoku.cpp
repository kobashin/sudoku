#include <iostream>
using namespace std;

int main(){
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

    for (int row = 0; row < 9; row++){
        for (int column = 0; column < 9; column++){
            cout << table[row][column] << " ";
        }
        cout << "\n";
    }

    return 0;
}