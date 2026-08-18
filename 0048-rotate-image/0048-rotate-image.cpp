class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // transpose
        for(int i = 0; i < rows; i++){
            for(int j = i + 1; j < cols; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse every row
        for(int i = 0; i < rows; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};