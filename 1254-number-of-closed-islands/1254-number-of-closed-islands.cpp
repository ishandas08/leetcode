class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        function<void(int,int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 1)
                return;

            grid[i][j] = 1;

            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        };

        for (int i = 0; i < m; i++) {
            dfs(i, 0);
            dfs(i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(0, j);
            dfs(m - 1, j);
        }

        int count = 0;

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(i, j);
                }
            }
        }

        return count;
    }
};