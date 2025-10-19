class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size(), ans = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_set<int> ev, od;

            for (int j = i; j < n; j++) {
                if (nums[j] & 1) {
                    od.insert(nums[j]);
                } else {
                    ev.insert(nums[j]);
                }
                
                if (ev.size() == od.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};