class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(begin(nums), end(nums)) + k;

        map<int, int> mp;
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            int l = max(nums[i] - k, 0);
            int r = min(nums[i] + k, maxVal);

            mp[l]++;
            mp[r + 1]--;

            mp[nums[i]] += 0;
        }

        int ans = 1;
        int sum = 0;

        for (auto& [f, s] : mp) {
            int target = f;
            s += sum;

            int targetFreq = freq[target];
            int needConversion = s - targetFreq;

            int maxPossibleFreq = min(needConversion, numOperations);

            ans = max(ans, targetFreq + maxPossibleFreq);

            sum = s;
        }

        return ans;
    }
};
