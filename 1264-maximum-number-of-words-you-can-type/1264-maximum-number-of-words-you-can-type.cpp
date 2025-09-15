class Solution {
public:
    int canBeTypedWords(string txt, string b) {
        unordered_set<char> st;
        for (int i = 0; i < b.size(); i++) {
            st.insert(b[i]);
        }

        int ans = 0,words = 1;

        for (int i = 0; i < txt.size(); i++) {
            if(txt[i] == ' '){
                words++;
            }
        }

        cout<<words;
        for (int i = 0; i < txt.size(); i++) {
            if (st.count(txt[i])) {
                while (i < txt.size()) {
                    if (txt[i] == ' ') {
                        break;
                    }
                    i++;
                }
                ans++;
            }
        }
        return words - ans;
    }
};