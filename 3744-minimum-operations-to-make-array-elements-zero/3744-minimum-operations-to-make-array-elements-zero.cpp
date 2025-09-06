#define ll long long

class Solution {
public:
    ll solve(ll l, ll r) {
        ll L = 1;
        ll S = 1;
        ll steps = 0;

        while (L <= r) {
            ll R = 4 * L - 1;

            ll start = max(L, l);
            ll end = min(R, r);

            if (start <= end) {
                steps += (end - start + 1) * S;
            }

            S += 1;
            L *= 4;
        }

        return steps;
    }

    long long minOperations(vector<vector<int>>& queries) {
        ll ans = 0;

        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];

            ll steps = solve(l, r);

            ans += ceil(steps / 2.0);
        }

        return ans;
    }
};
