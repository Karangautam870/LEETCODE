class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0;
        int sum2 = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            sum1 += nums[i];
        }

        for (int i = 0; i < n - 1; i++) {
            sum2 += nums[i];
            sum1 -= nums[i];
            if (!((sum1 - sum2) & 1)) {
                ans++;
            }
        }
        return ans;
    }
};
