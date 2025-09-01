class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    // initialization
    void initDSU(int n) {
        rank.assign(n, 0);
        parent.assign(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) {
            return;
        }

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int offset = 10001;
        initDSU(20005);

        unordered_set<int> st;

        int cmp = 0;
        for (auto& it : stones) {
            int row = it[0];
            int col = it[1] + offset;

            Union(row, col);
            st.insert(row);
            st.insert(col);
        }

        for (auto& x : st) {
            if (find(x) == x) {
                cmp++;
            }
        }

        return stones.size() - cmp;
    }
};
