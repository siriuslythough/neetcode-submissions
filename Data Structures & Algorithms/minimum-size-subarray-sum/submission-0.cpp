class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // check if sum < target (infeasible) (this can be done because its an array of positive integers, so if the total sum is less, there is no subarray too)
        int check = 0;
        for(int i : nums){
            check+=i;
        }
        if(check < target) return 0;
        int minlen = 1e9;
        int l = 0, r = 0;
        int sum = 0; 
        while(r<nums.size()){ 
            if(sum+nums[r]<target){sum+=nums[r]; r++;}
            else {
                minlen = min(minlen, r-l+1);
                sum -= nums[l];
                l++;
            }
        }
        return minlen;
    }
};