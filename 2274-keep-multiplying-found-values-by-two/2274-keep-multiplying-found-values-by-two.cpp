class Solution {
public:
    int findFinalValue(vector<int>& nums, int ans) {
        int n = nums.size();

        unordered_set<int>st(nums.begin(),nums.end());

        for(int i = 0;i < n;i++){
            if(st.count(ans)){
                ans *= 2;
            }
        }
        return ans;
    }
};