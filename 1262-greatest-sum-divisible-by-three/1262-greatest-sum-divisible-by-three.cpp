class Solution {
public:
    using ll = long long;
    vector<vector<ll>> dp;
    int n;
    ll solve(vector<int>& nums, int i, int rem) {
        if (i == n) {
            if (rem == 0) {
                return 0;
            }
            return LLONG_MIN / 4;
        }

        if (dp[i][rem] != -1) {
            return dp[i][rem];
        }

        ll take = nums[i] + solve(nums, i + 1, (rem - (nums[i] % 3) + 3) % 3);

        ll skip = solve(nums, i + 1, rem);

        if (take > skip) {
            dp[i][rem] = take;
        } else {
            dp[i][rem] = skip;
        }

        return dp[i][rem];
    }

    int maxSumDivThree(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<ll>(3, -1));
        return solve(nums, 0, 0);
    }
};
