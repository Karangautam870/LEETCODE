class Solution {
public:
    int numWaterBottles(int nb, int n) {
        int ans = nb;       
        int a = nb;   

        while (a >= n) {
            ans += a / n;           
            a = (a % n) + a / n;
        }

        return ans;
    }
};
