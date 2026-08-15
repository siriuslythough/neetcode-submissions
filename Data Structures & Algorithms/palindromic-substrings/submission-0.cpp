class Solution {
public:
    int countSubstrings(string s) {
        // again this needs a binary type memo, 1 if a palindrome i->j, else 0
        // so just do that and sum up the counts of the dp[i][j] = true
        int n = s.size();
        int num = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i<n; i++){
            dp[i][i] = true;
            num++;
        }
        for(int i = n-1; i>=0; i--){
            for(int j = i+1; j<n; j++){
                if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    num++;
                }
            }
        }
        return num;
    }
};
