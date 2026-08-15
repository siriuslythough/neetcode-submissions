class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i<n; i++){
            dp[i][i] = true; // single character substring will have length 1 palindrome 
        }
        int start = 0;
        int max_len = 1;
        // substring and subsequence will only differ in the dp update rules, flow will be the same
        for(int i = n-1; i>=0; i--){ // build from the back
            for(int j = i+1; j<n; j++){
                // see the main sthing is you need to have results about continuous sections, 
                // so you just need to check in your dp if i to j is a palindrome or not
                // if not, let it be false form the initialization itself.
                if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])){ 
                    dp[i][j] = true;
                    if(j-i+1>max_len){
                        start = i;
                        max_len = j-i+1;
                    }
                }
            }
        }
        return s.substr(start, max_len); 
    }
};
