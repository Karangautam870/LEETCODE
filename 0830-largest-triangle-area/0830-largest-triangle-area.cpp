class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& pt) {
        int n = pt.size();
        double ans = 0;

        for (int i = 0; i < n; i++) {
            int x1 = pt[i][0];
            int y1 = pt[i][1];

            for (int j = i + 1; j < n; j++) {
                int x2 = pt[j][0];
                int y2 = pt[j][1];
                
                for (int k = j + 1; k < n; k++) {
                    int x3 = pt[k][0]; 
                    int y3 = pt[k][1]; 

                    double area = abs(x1 * (y2 - y3) +
                                      x2 * (y3 - y1) +
                                      x3 * (y1 - y2));

                    ans = max(ans, area / 2.0);
                }
            }
        }
        return ans;
    }
};
