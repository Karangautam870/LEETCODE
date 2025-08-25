class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, vector<int>> mp;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        bool f = 1;

        for (int i = 0; i < mp.size(); i++) {
            if (f) {
                reverse(mp[i].begin(), mp[i].end());
            }
            for (int val : mp[i]) {
                ans.push_back(val);
            }
            f = (f == 0) ? 1 : 0;
        }

        return ans;
    }
};