class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int l = 0;
        int r = sum;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (l == r) {
                    ans += 2;
                }else if(abs(r - l) == 1) {
                    ans++;
                }
            } else {
                l += nums[i];
                r -= nums[i];
            }
        }
        return ans;
    }
};