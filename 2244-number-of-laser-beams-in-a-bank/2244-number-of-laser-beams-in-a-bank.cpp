class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0;

        for (string& row : bank) {
            int cnt = 0;
            for (char c : row) {
                if (c == '1') {
                    cnt++;
                }
            }

            if (cnt > 0) {
                ans += prev * cnt;
                prev = cnt;
            }
        }

        return ans;
    }
};
