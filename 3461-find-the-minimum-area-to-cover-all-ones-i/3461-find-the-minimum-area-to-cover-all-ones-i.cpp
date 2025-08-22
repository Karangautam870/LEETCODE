class Solution {
public:
    int minimumArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int right = 0, bottom = 0,ans = 0;
        int top = INT_MAX , left = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    left = min(j,left);
                    right = max(j, right);
                }
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (mat[i][j] == 1) {
                    top = min(i,top);
                    bottom = max(i, bottom);
                }
            }
        }

        return (right - left + 1) * (bottom - top + 1);
    }
};