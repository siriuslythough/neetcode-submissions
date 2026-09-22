class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        int i;
        while(l<=r){
            i = l + (r-l)/2;
            if(nums[i]==target) return i;
            else if(nums[i]<target) l = i+1;
            else r = i-1;
        }
        return -1;
    }
};
