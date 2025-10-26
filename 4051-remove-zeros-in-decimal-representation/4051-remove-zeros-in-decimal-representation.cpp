class Solution {
public:
    long long solve(long long n){
        long long ans = 0;
        while(n > 0){
            if(n % 10 != 0){
                ans = ans * 10 + n % 10;
            }
            n /= 10;
        }
        string k = to_string(ans);
        reverse(k.begin(),k.end());
        return stoll(k);
    }
    long long removeZeros(long long n) {
        return solve(n);
    }
};