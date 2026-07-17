class Solution {
public:
    int rob(vector<int>& nums) {
        // for each i, you can have the next robbed house
        // on the left from 0 <-> (i-2), and on the right from (i+2) <-> n-1
        // so clearly its a recursive problem, you stand at i, look for max from left and right
        int rob2 = 0;
        int rob1 = 0;
        // [rob2, rob1, nums[i], nums[i+1],...]
        int temp;
        for(int i = 0; i<nums.size(); i++){
            temp = max(nums[i]+rob2, rob1);
            rob2 = rob1;
            rob1 = temp;
        }
        return rob1;
    }
};
