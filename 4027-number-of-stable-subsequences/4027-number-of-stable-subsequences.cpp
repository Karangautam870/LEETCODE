class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int n;
    int solve(vector<int>& arr, int i, int odd, int even) {
        if (i >= n) {
            return 0;
        }

        if (dp[i][odd][even] != -1) {
            return dp[i][odd][even];
        }

        int take = 0;
        if ((arr[i] & 1) && odd < 2) {
            take = (1 + solve(arr, i + 1, odd + 1, 0)) % mod;
        } else if (!(arr[i] & 1) && even < 2) {
            take = (1 + solve(arr, i + 1, 0, even + 1)) % mod;
        } else if (odd < 2 && even < 2) {
            take = (1 + solve(arr, i + 1, odd + 1, even + 1)) % mod;
        }

        int skip = solve(arr, i + 1, odd, even);

        return dp[i][odd][even] = (take + skip) % mod;
    }

    int countStableSubsequences(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<vector<int>>(3, vector<int>(3, -1)));

        return solve(nums, 0, 0, 0);
    }
};