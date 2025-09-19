class Spreadsheet {
public:
    
    vector<vector<int>> arr;
    
    void setCell(string cell, int value) {
        int col = tolower(cell[0]) - 'a';
        int row = 0;
        for(int i = 1;i < cell.size();i++){
            row = row * 10 + cell[i] - '0';
        }

        arr[row][col] = value;
        // cout<<row<< ","<<col<<" - " << value << endl;
    }
    
    void resetCell(string cell) {
        int col = tolower(cell[0]) - 'a';
        int row = 0;

        for(int i = 1;i < cell.size();i++){
            row = row * 10 + cell[i] - '0';
        }

        arr[row][col] = 0;
    }
    
    int getValue(string s) {
        string s1 = "" , s2 = "";
        int i = 1;

        // s1
        while(i < s.size() && s[i] != '+'){
            s1 += s[i];
            i++;
        }
        // cout<<s1<<endl;
        i++;
        // s2
        while(i < s.size()){
            s2 += s[i];
            i++;
        }
        // cout<<s2<<endl;

        i = 1;

        int ans = 0;
        int col1 = 0 , row1 = 0,sum1 = 0;
        int col2 = 0 , row2 = 0,sum2 = 0;

        // s1
        if(isalpha(s1[0])){
            col1  = tolower(s1[0]) - 'a';
            while(i < s1.size()){
                row1 = row1 * 10 + s1[i] - '0';
                i++;
            }
            ans += arr[row1][col1];
        }else{
            i = 0;
            while(i < s1.size()){
                sum1 = sum1 * 10 + s1[i] - '0';
                i++;
            }
            ans += sum1;
        }

        i = 1;
        // s2
        if(isalpha(s2[0])){
            col2  = tolower(s2[0]) - 'a';
            while(i < s2.size()){
                row2 = row2 * 10 + s2[i] - '0';
                i++;
            }
            ans += arr[row2][col2];
        }else{
            i = 0;
            while(i < s2.size()){
                sum2 = sum2 * 10 + s2[i] - '0';
                i++;
            }
            ans += sum2;
        }
        return ans;
    }

    Spreadsheet(int rows) {
        arr.assign(rows + 2,vector<int>(26,0));
    }
};
