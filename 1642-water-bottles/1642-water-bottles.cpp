class Solution {
public:
    int numWaterBottles(int nb, int n) {
        int ans = nb;       

        while (nb >= n) {
            ans += nb / n;           
            nb = (nb % n) + nb / n;
        }

        return ans;
    }
};
