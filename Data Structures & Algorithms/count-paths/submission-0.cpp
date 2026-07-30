class Solution {
public:
    int uniquePaths(int m, int n) {
        // Go for a bottom-up approach
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        dp[m-1][n-1] = 1;
        // you build row by row, parse across columns, pick up right and below values
        for(int i=m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                dp[i][j] += dp[i+1][j] + dp[i][j+1]; 
            }
        }
        return dp[0][0];
    }
};
