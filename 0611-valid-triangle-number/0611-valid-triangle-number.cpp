class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        
        sort(nums.begin(), nums.end());

        for (int k = n - 1; k >= 0; k--) {
            int c = nums[k];

            int i = 0, j = k - 1;

            while(i < j){
                int a = nums[i];
                int b = nums[j];

                if(a + b > c){
                    ans += (j - i);
                    j--;
                }else{
                    i++;
                }
            }
            
        }
        return ans;
    }
};