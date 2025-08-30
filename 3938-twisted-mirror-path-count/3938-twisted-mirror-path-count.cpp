class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n, m;
    int mod = 1e9 + 7;
    
    int solve(vector<vector<int>>& mat, int i, int j, bool dir) {
        if (i >= n || j >= m || i < 0 || j < 0)  {
            return 0;
        }
        
        if (i == n - 1 && j == m - 1) {
            return 1;
        }
        
        int ans = 0;

        if(dp[i][j][dir] != -1){
            return dp[i][j][dir];
        }
        
        if (mat[i][j] == 1) {
            if (dir) {
                ans = (ans + solve(mat, i, j + 1, 0)) % mod;
            } else {
                ans = (ans + solve(mat, i + 1, j, 1))% mod;
            }
        }else{
            ans = (ans + solve(mat, i + 1, j, 1))% mod;
            ans = (ans + solve(mat, i, j + 1, 0))% mod;
        }
        
        return dp[i][j][dir] = ans % mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        dp.assign(n, vector<vector<int>>(m, vector<int>(2,-1)));
        return solve(grid, 0, 0, 0);
    }
};