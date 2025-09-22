class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> count;

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

        int maxFreq = 0;
        
        for (auto& i : count) {
            maxFreq = max(maxFreq, i.second);
        }

        int ans = 0;
        
        for (auto& i : count) {
            if (i.second == maxFreq) {
                ans += i.second;
            }
        }
        return ans;
    }
};
