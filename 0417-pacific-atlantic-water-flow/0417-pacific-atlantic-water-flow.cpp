class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& ht, vector<vector<bool>>& vis, int i, int j) {
        vis[i][j] = true;

        for (auto& d : dirs) {
            int i_ = i + d[0];
            int j_ = j + d[1];

            if (i_ >= 0 && j_ >= 0 && i_ < n && j_ < m && !vis[i_][j_] &&
                ht[i_][j_] >= ht[i][j]) {
                dfs(ht, vis, i_, j_);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        n = ht.size();
        m = ht[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, 0));
        vector<vector<bool>> atl(n, vector<bool>(m, 0));

        // Pacific: top row and left column
        for (int i = 0; i < n; i++) {
            dfs(ht, pac, i, 0);
        }
        for (int j = 0; j < m; j++) {
            dfs(ht, pac, 0, j);
        }

        // Atlantic: bottom row and right column
        for (int i = 0; i < n; i++) {
            dfs(ht, atl, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            dfs(ht, atl, n - 1, j);
        }
        
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
