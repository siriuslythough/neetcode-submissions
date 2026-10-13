class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        int leave_0 = search(nums, 1,n-1);
        int leave_1 = search(nums, 0, n-2);
        return max(leave_0, leave_1);
    }
private:
    int search(vector<int>& nums, int start, int end){
        if(start==end) return nums[start];
        int p2 = 0, p1 = 0;
        for(int i = start; i<=end; i++){
            int curr = max(nums[i] + p2, p1);
            p2 = p1;
            p1 = curr;
        }
        return p1;
    }
};
