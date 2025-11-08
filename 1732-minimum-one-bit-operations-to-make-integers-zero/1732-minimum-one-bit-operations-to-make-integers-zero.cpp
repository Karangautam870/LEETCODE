class Solution {
public:
    int solve(int n){
        int ans = 0;
        while (n) {
            ans ^= n;
            n >>= 1;
        }
        return ans;
    }
    int minimumOneBitOperations(int n) {
        return solve(n);
    }
};