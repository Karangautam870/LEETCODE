class Solution {
public:
    unordered_set<string> st;
    string k;

    int bfs(string& s) {
        if (st.count(s)) {
            return -1;
        }

        queue<string> q;
        q.push(s);
        st.insert(s);

        int ans = 0;

        while (!q.empty()) {
            int m = q.size();
            while (m--) {
                string curr = q.front();
                q.pop();

                if (curr == k) {
                    return ans;
                }

                for (int i = 0; i < s.size(); i++) {
                    char ch = curr[i];

                    // inc
                    curr[i] = (ch == '9') ? '0' : ch + 1;
                    if (st.count(curr) == 0) {
                        q.push(curr);
                        st.insert(curr);
                    }

                    // dec
                    curr[i] = (ch == '0') ? '9' : ch - 1;
                    if (st.count(curr) == 0) {
                        q.push(curr);
                        st.insert(curr);
                    }

                    curr[i] = ch; 
                }
            }
            ans++;
        }
        return -1;
    }

    int openLock(vector<string>& de, string target) {
        k = target;

        for (int i = 0; i < de.size(); i++) {
            st.insert(de[i]);
        }

        string s(k.size(), '0');

        return bfs(s);
    }
};
