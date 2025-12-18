class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else {
                low--;  // treat as ')'
                high++; // treat as '('
            }

            // too many ')'
            if (high < 0) {
                return 0;
            }
            // '*' can fix this
            if (low < 0) {
                low = 0;
            }
        }

        return low == 0;
    }
};
