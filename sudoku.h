struct tableInfo {
    int table[9][9];
    int candidates[9][9][9];
};

class SudokuTable{
    public:
        tableInfo tableInfo;
        void getTable();
        void getCandidates();
};
