class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        auto lambda = [](vector<int>& point1, vector<int>& point2) {
            // if equal sort with y value in descending order
            if (point1[0] == point2[0]) {
                return point1[1] > point2[1];
            }
            return point1[0] < point2[0];
        };

        sort(points.begin(), points.end(), lambda);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];   // upper left

            int best_y = INT_MIN;

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];   // lower right

                //(x2, y2) must be above (x1, y1)
                if (y2 > y1) {
                    continue;
                }

                if (y2 > best_y) {
                    ans++;
                    best_y = y2;
                }
            }
        }

        return ans;
    }
};