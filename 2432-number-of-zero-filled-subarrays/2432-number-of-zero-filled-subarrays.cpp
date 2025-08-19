#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0,cnt = 0; 

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                cnt++;
                ans += cnt;
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};