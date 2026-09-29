class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        int m;
        while(l<r){ // for convergence like problems, keep l as what you want and strict inequality l<r to not cross
            m = l + (r-l)/2;
            if(nums[m]>nums[nums.size()-1]) l = m+1;
            else r = m;
        }
        return nums[l];
    }
};
