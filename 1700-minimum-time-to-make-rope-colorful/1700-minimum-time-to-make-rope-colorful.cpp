class Solution {
public:
    int minCost(string s, vector<int>& t) {
        int n = s.size();
        int ans = 0,sum = t[0], maxi = t[0];

        for(int i = 1;i < n;i++){
            if(s[i] == s[i - 1]){
                sum += t[i];
                maxi = max(t[i],maxi);
            }else{
                ans += (sum - maxi);
                sum = t[i];
                maxi = t[i];
            }
        }
        ans += (sum - maxi);
        return ans;
    }
};