class Solution {
public:
    string ans;
    unordered_set<string> st;
    int n;

    void dfs(string curr, int a, int b) {
        st.insert(curr);
        ans = min(curr, ans);

        string temp = curr;
        for (int i = 1; i <= n; i += 2) {
            temp[i] = (temp[i] - '0' + a) % 10 + '0';
        }
        if (st.count(temp) == 0) {
            dfs(temp, a, b);
        }
        string k = curr.substr(b) + curr.substr(0, b);

        if (st.count(k) == 0) {
            dfs(k, a, b);
        }
    }

    void bfs(string s, int a, int b) {
        queue<string> q;
        q.push(s);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            ans = min(curr, ans);

            // add
            string temp = curr;
            for (int i = 1; i <= n; i += 2) {
                temp[i] = (temp[i] - '0' + a) % 10 + '0';
            }

            if (st.count(temp) == 0) {
                q.push(temp);
                st.insert(temp);
            }

            // rotate
            // substr(pos, len)
            string k = curr.substr(b) + curr.substr(0, b);

            if (st.count(k) == 0) {
                q.push(k);
                st.insert(k);
            }
        }
    }

    string findLexSmallestString(string s, int a, int b) {
        n = s.size();
        ans = s;
        // bfs(s,a,b);
        dfs(s, a, b);
        return ans;
    }
};