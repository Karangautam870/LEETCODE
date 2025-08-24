class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        int i = 0 , j = 0;

        while(j < nums.size()){

            if(nums[j] == 0){
                cnt++;
            }

            while(cnt > 1){
                if(nums[i] == 0){
                    cnt--;
                }
                i++;
            }
            ans = max(ans,j - i);
            j++;
        }
        return ans;
    }
};