class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n);
        a[0] = nums[0];
        for(int i = 1; i<n; i++){
            a[i] = max(a[i-1]+nums[i], nums[i]);
        }
        return *max_element(a.begin(), a.end());
    }
};
