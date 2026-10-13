class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int mincoins = dfs(amount, coins, dp);
        return (mincoins==INT_MAX)?-1:mincoins;
    }
private:
    int dfs(int amount, vector<int>& coins, vector<int>& dp){
        if(amount == 0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int res = INT_MAX;
        for(int coin : coins){
            if(amount-coin>=0){
                int ways = dfs(amount-coin, coins, dp);
                if(ways!=INT_MAX) res = min(res, 1+ways);
            }
        }
        return dp[amount] = res;
    }
};
