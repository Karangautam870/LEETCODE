class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int sum = 0;

        for(int i = 0; i < k;i++){
            sum += nums[i];
        } 

        for(int i = n - k; i < n;i++){
            sum -= nums[i];
        }
        return abs(sum);
    }
};