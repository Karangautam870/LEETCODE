class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) {
                    if (j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i][j - 1] + 1;
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) {
                    int val = dp[i][j];
                    for (int k = i; k >= 0 && val > 0; k--) {
                        val = min(val, dp[k][j]);
                        ans += val;
                    }
                }
            }
        }

        return ans;
    }
};
