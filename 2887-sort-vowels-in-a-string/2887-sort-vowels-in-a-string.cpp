class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                      'A', 'E', 'I', 'O', 'U'};
        vector<char> vow;

        for (char c : s) {
            if (vowels.count(c)) {
                vow.push_back(c);
            }
        }

        sort(vow.begin(), vow.end());

        string ans = "";
        int idx = 0;

        for (char c : s) {
            if (vowels.count(c)) {
                ans.push_back(vow[idx++]);
            } else {
                ans.push_back(c);
            }
        }

        return ans;
    }
};