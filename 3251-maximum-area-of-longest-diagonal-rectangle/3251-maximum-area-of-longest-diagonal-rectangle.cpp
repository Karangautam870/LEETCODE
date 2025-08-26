class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& mat) {
        int n = mat.size();

        int ans = 1;
        int diag = 0; 

        for (int i = 0; i < n; i++) {
            int d = mat[i][0] * mat[i][0] + mat[i][1] * mat[i][1];

            int area = mat[i][0] * mat[i][1];

            if (d > diag) {
                diag = d;
                ans = area;
            } else if (d == diag) {
                ans = max(ans, area);
            }
        }

        return ans;
    }
};
