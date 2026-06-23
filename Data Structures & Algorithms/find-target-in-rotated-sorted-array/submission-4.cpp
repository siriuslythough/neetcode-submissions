class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int m;
        while(l<=r){
            m = l + (r-l)/2;
            if(nums[m]==target) return m;
            else if(nums[l]<=nums[m]){//left part is sorted, and <= is needed cause if not integer,
                                      //mid always goes to the jus tlower index, hence it can be like m==l
                if(nums[l]<=target && target<=nums[m]) r=m-1; //if target is in left part
                else l = m+1; //if tagret is in right part
            }else{//right part is sorted
                if(nums[r]>=target && target>=nums[m]) l = m+1; //if target is in right part
                else r = m-1; //if target is in left part
            }
        }
        return -1;
    }
};
