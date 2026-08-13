class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Put ALL initially rotten oranges in queue
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == 2)
                    q.push({r, c});

                else if (grid[r][c] == 1)
                    fresh++;
            }
        }

        int minutes = 0;

        int directions[4][2] = {
            {-1, 0},  // up
            {1, 0},   // down
            {0, -1},  // left
            {0, 1}    // right
        };

        while (!q.empty() && fresh > 0) {

            int size = q.size();

            // Process ONE complete minute
            for (int i = 0; i < size; i++) {

                auto [r, c] = q.front();
                q.pop();

                for (auto& dir : directions) {

                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr >= 0 && nr < rows &&
                        nc >= 0 && nc < cols &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        fresh--;

                        q.push({nr, nc});
                    }
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};