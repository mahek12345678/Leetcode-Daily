class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size();
        int m = grid[0].size();
        int total = n * m;

        vector<long long> arr(total);
        int k = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[k++] = grid[i][j] % MOD;
            }
        }

        vector<long long> suffix(total, 1);

        for (int i = total - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % MOD;
        }

        vector<vector<int>> ans(n, vector<int>(m));

        long long prefix = 1;
        k = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = (prefix * suffix[k]) % MOD;
                prefix = (prefix * arr[k]) % MOD;
                k++;
            }
        }

        return ans;
    }
};