class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // BRUTE FORCE, using a pair to store the indicez recorded as zero
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows;
        vector<int> cols;
        for(int i = 0;  i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j]==0){
                    rows.push_back(i); 
                    cols.push_back(j);
                }
            }
        }
        for(int r : rows){
            for(int j = 0; j<n ;j++){
                matrix[r][j] = 0;
            }
        }
        for(int c : cols){
            for(int i = 0; i<m; i++){
                matrix[i][c] = 0;
            }
        }
    }
};
