class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans = 0;
        int i = 0;

        sort(nums.begin(), nums.end());
        while (i < nums.size() - 2) {
            if (nums[i] + nums[i + 1] > nums[i + 2]) {
                ans = max(nums[i] + nums[i + 1] + nums[i + 2], ans);
            }
            i++;
        }
        return ans;
    }
};