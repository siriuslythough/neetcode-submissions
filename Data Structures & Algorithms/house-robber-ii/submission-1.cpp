class Solution {
public:
    int rob(vector<int>& nums) {
        // take two vectors, one that has head (zero element) and one that does not have.
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> nums1;
        vector<int> nums2;
        copy(nums.begin()+1, nums.end(), back_inserter(nums1));
        copy(nums.begin(), nums.end()-1, back_inserter(nums2));
        vector<int> dp1(n-1, -1);
        vector<int> dp2(n-1, -1);
        return max(dfs(0, dp1, nums1), dfs(0, dp2, nums2));
    }
private:
    int dfs(int i, vector<int>& dp, vector<int>& nums){
        int n = nums.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int d2 = (i+2<n)?dfs(i+2, dp, nums):0;
        int d3 = (i+3<n)?dfs(i+3, dp, nums):0;
        return dp[i] = max(nums[i]+d2, (i+1<n)?nums[i+1]+d3:0);
    }
};
