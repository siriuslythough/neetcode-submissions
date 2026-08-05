class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        // dp[i][a] is the number of distinct ways to build amount a using coings from 0 onwards
        for(int k = 0; k<n+1; k++){
            dp[k][0] = 1;
        }
        for(int i = n-1; i>=0; i--){
            for(int a = 0; a<amount+1; a++){
                if(a>=coins[i]){
                    dp[i][a] = dp[i+1][a] + dp[i][a-coins[i]]; // if you take that coin, or if you use everything else
                }
            }
        }
        return dp[0][amount];
    }
};
