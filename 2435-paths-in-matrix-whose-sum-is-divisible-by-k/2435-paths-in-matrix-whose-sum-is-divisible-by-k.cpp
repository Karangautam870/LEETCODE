class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n, m, ans = 0, mod = 1e9 + 7, k;

    int solve(vector<vector<int>>& mat, int i, int j, int sum) {
        if (i == n - 1 && j == m - 1) {
            if (sum % k == 0) {
                return 1;
            }
            return 0;
        }

        if (dp[i][j][sum] != -1) {
            return dp[i][j][sum];
        }

        long long w = 0;

        if (i + 1 < n) {
            w += solve(mat, i + 1, j, (sum + mat[i + 1][j]) % k);
        }
        if (j + 1 < m) {
            w += solve(mat, i, j + 1, (sum + mat[i][j + 1]) % k);
        }

        return dp[i][j][sum] = w % mod;
    }
    int numberOfPaths(vector<vector<int>>& mat, int K) {
        n = mat.size(), m = mat[0].size(), k = K;
        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return solve(mat, 0, 0, (mat[0][0]) % k);
    }
};
