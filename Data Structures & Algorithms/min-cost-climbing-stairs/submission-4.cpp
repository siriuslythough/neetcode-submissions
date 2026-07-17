class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(func(0, dp, cost), func(1, dp, cost));
        // at each step i, min cost to reach top is 
        // cost[i] + (min cost to reach top from i+1 or i+2)
        // This is "top-down" BECAUSE you are asking:
        //      What is the cost if I am to start from 0th or 1st step
        // Compared to what they call a "bottom-up" where we would have
        // Solved the smaller sub-problem of n-1th and n-2th steps cost
        // and built back to the larger problem, that is cost from 0th or 1st step
    }
private:
    int func(int idx, vector<int>& dp, vector<int>& cost){
        if(idx >= cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = cost[idx] + min(func(idx+1, dp, cost), func(idx+2, dp, cost));
    }
};

