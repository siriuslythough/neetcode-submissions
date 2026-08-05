class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> dp(n, 1);
        int max_len = 1;
        for(int i = n-1; i>=0; i--){
            for(int j = i+1; j<n; j++){
                if(nums[i]<nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            max_len = max(max_len,dp[i]);
        }
        return max_len;
    }
};
