class Solution {
public:

    void dfs(vector<vector<char>>& grid, int r, int c) {

        // Base case: outside grid OR water/already visited
        if (r < 0 || r >= grid.size() ||
            c < 0 || c >= grid[0].size() ||
            grid[r][c] == '0') {
            return;
        }

        // Mark current land as visited
        grid[r][c] = '0';

        // Explore all 4 directions
        dfs(grid, r - 1, c);  // UP
        dfs(grid, r + 1, c);  // DOWN
        dfs(grid, r, c - 1);  // LEFT
        dfs(grid, r, c + 1);  // RIGHT
    }


    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int islands = 0;

        // Visit every cell
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                // Found a new island
                if (grid[r][c] == '1') {
                    islands++;

                    // Destroy/visit the entire island
                    dfs(grid, r, c);
                }
            }
        }

        return islands;
    }
};