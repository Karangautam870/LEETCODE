class Solution {
public:
    int mod = 1e9 + 7;
    int numSub(string s) {
        long long ans = 0;
        long long temp = 0;

        for(int i = 0; i < s.size();i++){
            if(s[i] == '1'){
                temp++;
            }else{
                ans = (ans + temp * (temp + 1) / 2) % mod;
                temp = 0;
            }
        }
        return (ans + temp * (temp + 1) / 2) %  mod;
    }
};