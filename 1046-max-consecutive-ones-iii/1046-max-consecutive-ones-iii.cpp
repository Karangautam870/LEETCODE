class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0,j = 0,ans = 0, cnt = 0,n = nums.size();

        while(j < n){
            if(nums[j] == 0){
                cnt++;
            }

            while(cnt > k){
                if(nums[i] == 0){
                    cnt--;
                }
                i++;
            }
            ans = max(j - i + 1,ans);
            j++;
        }
        return ans;
    }
};