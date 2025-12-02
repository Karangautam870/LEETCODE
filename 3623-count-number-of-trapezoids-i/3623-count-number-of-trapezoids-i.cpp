class Solution {
public:
    int mod = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& arr) {
        int n = arr.size(), ans = 0;
        unordered_map<int, int> mp;

        for (auto& it : arr) {
            mp[it[1]]++;
        }

        long long prevLines = 0;
        for (auto& [f, s] : mp) {

            long long hLines = (1LL * s * (s - 1) / 2) % mod;

            ans = (ans + (hLines * prevLines)) % mod;

            prevLines += hLines;
        }
        return ans;
    }
};