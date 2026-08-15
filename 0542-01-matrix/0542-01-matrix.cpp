class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> ans(m, vector<int>(n, -1));

        // Put all zeros in queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nr = r + row[k];
                int nc = c + col[k];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    ans[nr][nc] == -1) {

                    ans[nr][nc] = ans[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return ans;
    }
};