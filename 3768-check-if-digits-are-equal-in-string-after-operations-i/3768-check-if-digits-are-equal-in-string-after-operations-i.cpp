class Solution {
public:
    string solve(string& s) {
        string ans = "";
        for (int i = 1; i < s.size(); i++) {
            ans += to_string((s[i] - '0' + s[i - 1] - '0') % 10);
        }
        return ans;
    }

    bool hasSameDigits(string s) {
        while (s.size() > 1) {
            s = solve(s);
            if (s.size() == 2) {
                break;
            }
        }

        return s[0] == s[1];
    }
};