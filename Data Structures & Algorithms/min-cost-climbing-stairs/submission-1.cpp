class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(func(cost.size() - 1, dp, cost), func(cost.size() - 2, dp, cost));
    }
private:
    int func(int idx, vector<int>& dp, vector<int>& cost){
        if(idx == 0) return cost[0];
        if(idx == 1) return cost[1]; // this is used because question states
                                     // you can start at 0 or 1
                                     // and if idx==1, then starting at 1 is better
        if(dp[idx]!=-1) return dp[idx];
        int l = func(idx-1, dp, cost);
        int r = INT_MAX;
        if(idx>1) r = func(idx-2, dp, cost);
        return dp[idx] = cost[idx] + min(l,r);
    }
};
