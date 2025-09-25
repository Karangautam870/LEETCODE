class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& t, int i, int j) {
        if (i >= n) {
            return 0;
        }

        if (j >= t[i].size()) {
            return 0;
        }

        int incl = t[i][j] + solve(t, i + 1, j);
        int excl = t[i][j] + solve(t, i + 1, j + 1);

        return min(incl, excl);
    }

    int solveMem(vector<vector<int>>& t, int i, int j) {
        int n = t.size();

        if (i >= n) {
            return 0;
        }

        if (j >= t[i].size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int incl = t[i][j] + solve(t, i + 1, j);
        int excl = t[i][j] + solve(t, i + 1, j + 1);
        
        return dp[i][j] = min(incl, excl);
    }

    // O(N^2) --> Time Complexity
    int solveTab(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int>> dp(n);

        for (int i = 0; i < n; ++i) {
            dp[i] = vector<int>(t[i].size(), INT_MAX);
        }

        for (int j = 0; j < t[n - 1].size(); j++) {
            dp[n - 1][j] = t[n - 1][j];
            // storing the last last row of element
        }
        // since last row is already got used therefore use only remaining rows
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < t[i].size(); j++) {
                int incl = t[i][j] + dp[i + 1][j];
                int excl = t[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(incl, excl);
            }
        }
        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        dp.assign(n,vector<int>(triangle[0].size(), -1));
        
        // return solve(triangle, 0, 0);
        // return solveMem(triangle, 0, 0);
        return solveTab(triangle);
    }
};
