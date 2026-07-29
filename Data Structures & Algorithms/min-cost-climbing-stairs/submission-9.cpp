class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int f1 = cost[n-1];
        int f2 = cost[n-2];
        int prev;
        for(int i = n-3; i>=0; i--){
            prev = cost[i] + min(f2,f1);
            f1 = f2;
            f2 = prev;
        }
        return min(f1, f2);
    }
};
