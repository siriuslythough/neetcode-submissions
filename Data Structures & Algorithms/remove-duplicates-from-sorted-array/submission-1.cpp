class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i = 0; // unique element pointer
        int j = 1;
        int diff = 0;
        for(int j = 1; j<nums.size(); j++){ // reading pointer
            if(nums[i]!=nums[j]){i++; nums[i] = nums[j];} // overwrite that position in place
        }
        return i+1;
    }
};