class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        map<int, int> mp;
        int i = 0, j = 0;
        vector<int> ans(n - k + 1);

        while (j < n) {
            mp[nums[j]]++;
            if (j - i + 1 == k) {
                int sum = 0;
                vector<pair<int,int>> temp;

                for (auto& [f, s] : mp) {
                    temp.push_back({s,f});
                }

                sort(temp.begin(),temp.end(),cmp);
                int g = temp.size();
                for(int k = 0; k < min(x,g);k++){
                    sum += temp[k].first * temp[k].second;
                }

                ans[j - k + 1] = sum;

                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};