class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        vector<int> dp(amount+1, -1);
        int mincoins = dfs(coins, amount, dp);
        return (mincoins==INT_MAX)?-1:mincoins;
    }
private:
    int dfs(vector<int>& coins, int amount, vector<int>& dp){
        if(amount==0) return 0;
        if(dp[amount] != -1) return dp[amount];
        int res = INT_MAX;
        for(int coin : coins){
            if(amount-coin>=0){
                int sub = dfs(coins, amount-coin, dp);
                if(sub!=INT_MAX) res = min(res, 1+sub);
            }
        }
        return dp[amount] = res;
    }
};
