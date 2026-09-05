class Solution {
public:
    // dp approach, bottom-up
    // dp[i][0] is max profit from day i if we can buy further (we bough that day)
    // dp[i][1] is max profit from day i if we sold that day
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2,0));
        // dp[n][0] = d[n][1] = 0
        // dp[i][0] is max of skip or buy that day
        // dp[i][1] is max of skip or sell that day
        for(int i = prices.size()-1; i>=0; i--){
            dp[i][0] = max(dp[i+1][0], -prices[i]+dp[i+1][1]);
            dp[i][1] = max(dp[i+1][1], prices[i]+dp[i+1][0]);
        }
        return dp[0][0];
    }
};