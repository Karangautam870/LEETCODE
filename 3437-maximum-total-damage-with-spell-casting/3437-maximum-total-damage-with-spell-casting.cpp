class Solution {
public:
    using p = pair<int, long long>;
    using ll = long long;
    vector<ll> dp;
    int n;

    long long solve(vector<p>& vec, int i) {
        if (i >= n) {
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        ll skip = solve(vec, i + 1);
        ll take = vec[i].second;

        int j = i + 1;

        while (j < n && vec[j].first - vec[i].first <= 2) {
            j++;
        }

        take += solve(vec, j);

        return dp[i] = max(take, skip);
    }

    long long maximumTotalDamage(vector<int>& power) {

        unordered_map<int, long long> mp;
        for (auto it : power) {
            mp[it] += it;
        }

        vector<p> vec(mp.begin(), mp.end());
        n = vec.size();
        dp.assign(n, -1);
        sort(vec.begin(), vec.end());

        return solve(vec, 0);
    }
};