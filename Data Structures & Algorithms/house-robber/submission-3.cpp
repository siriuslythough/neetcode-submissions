class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return dfs(0,nums,dp);
    }
private:
    int dfs(int i, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int d2 = (i+2<n)?dfs(i+2, nums, dp):0;//handle the n-1 case, by simply making them 0, if cant
        int d3 = (i+3<n)?dfs(i+3, nums, dp):0;//handle the n-2 case, by simply making them 0, if cant
        // return and store value in dp
        return dp[i] = max(nums[i] + d2, (i+1<n)?nums[i+1] + d3:0); // had to check for i+1 validity also
    }
};
