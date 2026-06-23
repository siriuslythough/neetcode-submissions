class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int k;
        while(l<=r){
            k = (l+r)/2;
            if(nums[k]==target) return k;
            else if(nums[k]>target) r=k-1;
            else l=k+1;
        }
        return -1;
    }
};

