class Solution {
public:
    string longestPalindrome(string s) {
        // 2D DP, returns bool if contains palindrome
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int n = s.size();
        for(int i = 0; i<n; i++) dp[i][i] = true;
        int start = 0;
        int maxlen = 1;
        for(int i = n-1; i>=0; i--){
            for(int j = i+1; j<n; j++){
                if(s[i] == s[j] && (j-i<=2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    if(j-i+1>maxlen){
                        start = i; 
                        maxlen = j-i+1;
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
