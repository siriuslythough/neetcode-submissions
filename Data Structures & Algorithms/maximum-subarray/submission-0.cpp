class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ms = INT_MIN;
        for(int i = 0; i<n; i++){
            int rs = nums[i];
            ms = max(ms, rs);
            for(int j = i+1; j<n; j++){
                rs+=nums[j];
                ms = max(ms, rs);
            }
        }
        return ms;
    }
};
