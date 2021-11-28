void initCandidates(int table[9][9], int fixed[9][9], int candidates[9][9][9]);
void filterCandidates(int table[9][9], int fixed[9][9], int candidates[9][9][9]);
void filterRowCandidates(int row, int column, int table[9][9], int fixed[9][9], int candidates[9][9][9]);
void filterColumnCandidates(int row, int column, int table[9][9], int fixed[9][9], int candidates[9][9][9]);
void filterSubtableCandidates(int row, int column, int table[9][9], int fixed[9][9], int candidates[9][9][9]);
int countCandidates(int candidates[9]);
void fillTable(int table[9][9], int fixed[9][9], int candidates[9][9][9]);

struct tableInfo {
    int table[9][9];
    int fixed[9][9];
    int candidates[9][9][9];
};

class SudokuTable{
    public:
        tableInfo tableInfo;
        void getTable();
        void getFixed();
        void getCandidates();
        void countFilled();
};
