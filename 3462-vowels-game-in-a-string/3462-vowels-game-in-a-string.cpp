class Solution {
public:
    bool doesAliceWin(string s) {
        int n = 0;

        for (char ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                n++;
            }
        }

        if (n == 0) {
            return 0;
        }
        return 1;
    }
};