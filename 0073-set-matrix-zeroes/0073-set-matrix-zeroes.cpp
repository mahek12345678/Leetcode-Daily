class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        set<int> zeroRows;
        set<int> zeroCols;

        // First: original zero ki rows aur columns store karo
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                if(matrix[i][j] == 0){
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }

        // Second: un rows aur columns ko zero karo
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                if(zeroRows.count(i) || zeroCols.count(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};