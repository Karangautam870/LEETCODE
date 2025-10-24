class Solution {
public:
    bool solve(int n) {
        vector<int> f(10);
        while (n > 0) {
            f[n % 10]++;
            n /= 10;
        }

        for (int i = 0; i < 10; i++) {
            if (i != f[i] && f[i] > 0) {
                return 0;
            }
        }
        return 1;
    }

    int nextBeautifulNumber(int n) {

        for (int i = n + 1; i <= 1224444; i++) {
            if (solve(i)) {
                return i;
            }
        }

        return -1;
    }
};