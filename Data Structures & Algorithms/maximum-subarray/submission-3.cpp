class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int curr;
        int maxi = nums[0];
        for(int i = 1; i<n; i++){
            curr = max(prev+nums[i], nums[i]);
            maxi = max(maxi, curr);
            prev = curr;
        }
        return maxi;
    }
};
