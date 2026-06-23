class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> ss;
        for(int i = 0; i<nums.size(); i++){
            if(ss.empty()) ss.insert(nums[i]);
            else if(ss.count(nums[i])) return nums[i];
            ss.insert(nums[i]);
        }  
    }
};
