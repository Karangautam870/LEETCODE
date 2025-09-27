class Solution {
public:
    string majorityFrequencyGroup(string s) {

        map<int, pair<int, string>> mp;
        unordered_map<int, int> mp1;

        vector<int> f(26, 0);
        int n = s.size();
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            f[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (f[i] != 0) {
                mp[f[i]].first++;
                mp[f[i]].second += i + 'a';
            }
        }

        int maxi = 0;
        int a = 0;

        for (auto& it : mp) {
            int size = it.second.first;
            if (maxi < size) {
                maxi = size;
                ans = it.second.second;
                a = it.first;
            } else if (maxi == size) {
                int freq = it.first;
                if (freq > a) {
                    ans = ans = it.second.second;
                }
            }
        }

        return ans;
    }
};