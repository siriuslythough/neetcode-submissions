class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxP = 0;
        int minBuy = prices[0];
        for(int& sell : prices){
            maxP = max(maxP, sell-minBuy);
            minBuy = min(minBuy,sell);
        }
        return maxP;
    }
};
