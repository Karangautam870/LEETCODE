class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // bottom left
        for (int i = 0; i < n; i++) {
            vector<int> dia;
            int x = i, y = 0;
            while (x < n && y < n) {
                dia.push_back(grid[x][y]);
                x++;
                y++;
            }
            sort(dia.rbegin(), dia.rend());
            
            x = i, y = 0;
            for (int val : dia) {
                grid[x][y] = val;
                x++;
                y++;
            }
        }
        // top left
        for (int j = 1; j < n; j++) {
            vector<int> dia;
            int x = 0, y = j;
            while (x < n && y < n) {
                dia.push_back(grid[x][y]);
                x++;
                y++;
            }
            
            sort(dia.begin(), dia.end());
            
            x = 0, y = j;
            for (int val : dia) {
                grid[x][y] = val;
                x++;
                y++;
            }
        }

        return grid;
    }
};
