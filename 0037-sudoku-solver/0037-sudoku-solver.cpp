class Solution {
public:
    bool check(vector<vector<char>>& board, int row, int col, char val) {
        for (int i = 0; i < 9; i++) {
            // row col condition checking
            if (board[row][i] == val || board[i][col] == val) {
                return 0;
            }

            // 3 * 3 mat checking
            int r = 3 * (row / 3) + i / 3;
            int c = 3 * (col / 3) + i % 3;

            if (board[r][c] == val) {
                return 0;
            }
        }
        return 1;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (check(board, i, j, val)) {
                            board[i][j] = val;

                            // this solution is possible
                            if (solve(board)) {
                                return 1;
                            }

                            // backtrack
                            board[i][j] = '.';
                        }
                    }
                    // if no values are found
                    return 0;
                }
            }
        }
        // solution is found
        return 1;
    }

    void solveSudoku(vector<vector<char>>& board) { 
        solve(board);
    }
};