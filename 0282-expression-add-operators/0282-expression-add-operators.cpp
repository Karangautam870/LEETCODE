class Solution {
public:
    vector<string> ans;
    int k;
    // we need prev becouse of precedance of * is more than +,-
    void solve(string& s, string temp, int i, long long sum, long long prev) {

        if (i == s.size()) {
            if (sum == k) {
                ans.push_back(temp);
            }
            return;
        }

        string currStr = "";
        long long currNum = 0;

        for (int j = i; j < s.size(); j++) {
            // prevent numbers with leading zero 
            // j > i more than one digit like 05,032 all are invalid
            if (j > i && s[i] == '0') {
                break;
            }

            currStr += s[j];
            currNum = currNum * 10 + (s[j] - '0');

            if (i == 0) {
                // first number, start recursion
                solve(s, temp + currStr, j + 1, currNum, currNum);
            } else {
                // add '+'
                solve(s, temp + "+" + currStr, j + 1, sum + currNum, currNum);

                // add '-'
                solve(s, temp + "-" + currStr, j + 1, sum - currNum, -currNum);

                // add '*'
                solve(s, temp + "*" + currStr, j + 1,
                      sum - prev + prev * currNum, prev * currNum);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        k = target;

        solve(num, "", 0, 0, 0);
        return ans;
    }
};
