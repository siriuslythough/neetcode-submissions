class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // to buy or not to buy today
        int n = prices.size();
        vector<int> dp(n, 0);
        dp[n-1] = prices[n-1];
        int maxprof = 0;
        for(int i = n-2; i>=0; i--){
            dp[i] = max(dp[i+1], prices[i]);
            int profit = dp[i]-prices[i];
            maxprof = max(maxprof, profit);
        }
        return maxprof;
    }
};
