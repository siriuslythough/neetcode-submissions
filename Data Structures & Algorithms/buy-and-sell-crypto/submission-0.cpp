class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0, r = 1;
        int maxP = 0;
        while(r<n){
            if(prices[l]<prices[r]){
                maxP = max(maxP, prices[r]-prices[l]);
            }else{
                l=r;
            }
            r++;
        }
        return maxP;
    }
};
