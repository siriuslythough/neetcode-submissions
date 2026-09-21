class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> dp(n, 0);
        for(int i = n-2; i>=0; i--){
            int j = i+1;
            while(j<n && temperatures[j]<=temperatures[i]){
                if(dp[j]==0){
                    j = n;
                    break;
                }
                j+=dp[j];
            }
            if(j<n){
                dp[i] = j-i;
            }
        }
        return dp;
    }
};
