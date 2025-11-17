class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int a = -1;
        int b = 0;

        for(int i = 0; i < nums.size();i++){
            if(nums[i] == 1){
                a = i;
                break;
            }
        }

        if(a == -1){
            return 1;
        }

        for (int i = a + 1; i < nums.size(); i++) {
            if(nums[i] == 1){
                b = i;
                if(b - a - 1 < k){
                    return 0;
                }
                a = b;
            }
        }
        return 1;
    }
};