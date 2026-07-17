class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(func(0, dp, cost), func(1, dp, cost));
        // at each step i, min cost to reach top is 
        // cost[i] + (min cost to reach top from i+1 or i+2)
    }
private:
    int func(int idx, vector<int>& dp, vector<int>& cost){
        if(idx >= cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = cost[idx] + min(func(idx+1, dp, cost), func(idx+2, dp, cost));
    }
};

