class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int ans = 0, n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                nums[j] = (nums[j + 1] + nums[j]) % 10;
            }
            if (nums.size() == 1) {
                break;
            }
        }
        return nums[0];
    }
};