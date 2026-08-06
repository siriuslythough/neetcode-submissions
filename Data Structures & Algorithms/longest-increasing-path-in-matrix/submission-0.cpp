class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // dfs traversal until increasing?
        // store a 2d dp which tells from i what is the longest path seen between i and j (MEMO)
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxi = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                maxi = max(maxi, dfs(i,j,-1, dp, matrix));
            }
        }
        return maxi;
    }
private:
    int dfs(int i, int j, int prev, vector<vector<int>>& dp, vector<vector<int>>& matrix){
        if(i<0 || j<0 || i>=matrix.size() || j>= matrix[0].size()) return 0;
        if(matrix[i][j]<=prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        vector<vector<int>> dirs = {{1,0}, {-1,0},{0,1},{0,-1}};
        int res = 0;
        for(int l = 0; l<4; l++){
            int r = i + dirs[l][0];
            int c = j + dirs[l][1];
            res = max(res, dfs(r,c,matrix[i][j],dp,matrix)); // get the max from all direction
        }
        return dp[i][j] = 1+res;
    }
};
