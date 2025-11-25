class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int ans = 0, num = 0;

        while(ans < k){
            num = (num * 10 + 1) % k;
            ans++;
            if(num % k == 0){
                return ans;
            }
        }
        return -1;
    }
};