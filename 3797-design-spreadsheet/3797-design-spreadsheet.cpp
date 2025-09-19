class Spreadsheet {
public:
    unordered_map<string, int> mp;

    void setCell(string cell, int value) { 
        mp[cell] = value; 
    }

    void resetCell(string cell) { 
        mp.erase(cell); 
    }

    int getValue(string formula) {
        int pos = formula.find('+');
        string cell1 = formula.substr(1, pos - 1);
        string cell2 = formula.substr(pos + 1);

        int val1 = isalpha(cell1[0]) ? (mp.count(cell1) ? mp[cell1] : 0)
                                     : stoi(cell1);
        int val2 = isalpha(cell2[0]) ? (mp.count(cell2) ? mp[cell2] : 0)
                                     : stoi(cell2);

        return val1 + val2;
    }
    Spreadsheet(int rows) {}
};