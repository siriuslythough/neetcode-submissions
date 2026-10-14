class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 2D DP, updates on the basis of negative numbers between indices
        int res = nums[0];
        int curmin = 1, curmax = 1;
        for(int num : nums){
            int tmp = curmax*num;
            curmax = max(max(num*curmax, num*curmin), num);
            curmin = min(min(tmp, num*curmin), num);
            res = max(res, curmax);
        }
        return res;
    }
};
