class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int trapRainWater(vector<vector<int>>& ht) {
        int m = ht.size();
        int n = ht[0].size();

        priority_queue<pp, vector<pp>, greater<pp>> pq;
        // Min heap: {height, {row, col}}
        vector<vector<bool>> v(m, vector<bool>(n, false));

        // Left and rightmost columns
        for (int row = 0; row < m; row++) {
            for (int col : {0, n - 1}) {
                pq.push({ht[row][col], {row, col}});
                v[row][col] = true;
            }
        }
        
        // Top and bottom rows
        for (int col = 0; col < n; col++) {
            for (int row : {0, m - 1}) {
                pq.push({ht[row][col], {row, col}});
                v[row][col] = true;
            }
        }
        
        int ans = 0;

        while (!pq.empty()) {
            pp curr = pq.top();
            pq.pop();

            int h = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            // Find neighbors
            for (vector<int>& dir : dirs) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !v[i_][j_]) {
                    ans += max(h - ht[i_][j_], 0);
                    pq.push({max(h, ht[i_][j_]), {i_, j_}});
                    v[i_][j_] = true;
                }
            }
        }
        
        return ans;
    }
};
