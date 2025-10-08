class Solution {
public:
    int solve(vector<int>& p, int num, long long k) {
        int s = 0, e = p.size() - 1;
        int ans = p.size();

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (1LL * p[mid] * num >= k) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return p.size() - ans;
    }
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long k) {

        vector<int> ans(s.size(), 0);

        sort(p.begin(), p.end());

        for (int i = 0; i < s.size(); i++) {
            ans[i] = solve(p, s[i], k);
        }

        return ans;
    }
};