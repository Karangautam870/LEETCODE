class Solution {
public:
    unordered_set<char> st;
    map<string, vector<string>> mp;

    vector<string> validateCoupons(vector<string>& c, vector<string>& b,
                                   vector<bool>& a) {
        vector<string> ans;
        int n = a.size();

        for (char ch = 'a'; ch <= 'z'; ch++) {
            st.insert(ch);
            st.insert(toupper(ch));
        }

        st.insert('_');

        for (int i = 0; i < 10; i++) {
            st.insert(char('0' + i));
        }

        for (int i = 0; i < n; i++) {
            bool k = true;

            if (a[i]) {
                for (int j = 0; j < c[i].size(); j++) {
                    if (st.count(c[i][j]) == 0) {
                        k = false;
                        break;
                    }
                }
            }

            if ((b[i] == "electronics" || b[i] == "grocery" ||
                 b[i] == "pharmacy" || b[i] == "restaurant") &&
                k && a[i]) {
                mp[b[i]].push_back(c[i]);
            }
        }

        for (auto& it : mp) {
            sort(it.second.begin(), it.second.end());
            for (int i = 0; i < it.second.size(); i++) {
                if (isalnum(it.second[i][0]) || it.second[i][0] == '_') {
                    ans.push_back(it.second[i]);
                }
            }
        }

        return ans;
    }
};
