class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visit(n, vector<int>(m, 0));

        // Put ALL rotten oranges into queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visit[i][j] = 2;
                }
            }
        }

        bfs(grid, visit, q);

        // Check if any fresh orange remains
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visit[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }

    vector<int> row = {0, -1, 0, 1};
    vector<int> col = {1, 0, -1, 0};
    int time = 0;

    void bfs(vector<vector<int>>& grid,
             vector<vector<int>>& visit,
             queue<pair<pair<int, int>, int>>& q) {

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr.first.first;
            int c = curr.first.second;
            int t = curr.second;

            time = max(time, t);

            for (int i = 0; i < 4; i++) {
                int nrow = r + row[i];
                int ncol = c + col[i];

                if (nrow >= 0 && nrow < grid.size() &&
                    ncol >= 0 && ncol < grid[0].size() &&
                    visit[nrow][ncol] != 2 &&
                    grid[nrow][ncol] == 1) {

                    q.push({{nrow, ncol}, t + 1});
                    visit[nrow][ncol] = 2;
                }
            }
        }
    }
};