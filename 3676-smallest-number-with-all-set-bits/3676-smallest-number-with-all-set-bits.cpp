class Solution {
public:
    int solve(int n){
        int ans = 0;
        int i = 0;
        while(n > 0){
            ans += 1 << i;
            n >>= 1;
            i++;
        }
        return ans;
    }
    int smallestNumber(int n) {
        return solve(n);
    }
};