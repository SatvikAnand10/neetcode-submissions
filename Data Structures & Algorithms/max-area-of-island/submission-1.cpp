class Solution {
    int max_island = 0;

    int directions[4][2] = {
        {1, 0}, {-1, 0},
        {0, 1}, {0, -1}
    };

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {

                if (grid[r][c] == 1) {
                    bfs(grid, r, c);
                }
            }
        }

        return max_island;
    }

private:
    void bfs(vector<vector<int>>& grid, int r, int c) {
        int size = 1;

        queue<pair<int, int>> q;
        q.push({r, c});

        grid[r][c] = 0;

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            for (int i = 0; i < 4; i++) {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];

                if (nr >= 0 && nc >= 0 &&
                    nr < grid.size() &&
                    nc < grid[0].size() &&
                    grid[nr][nc] == 1) {

                    grid[nr][nc] = 0;
                    q.push({nr, nc});

                    size++;
                }
            }
        }

        max_island = max(max_island, size);
    }
};