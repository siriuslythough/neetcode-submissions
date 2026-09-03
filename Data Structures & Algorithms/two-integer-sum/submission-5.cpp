class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // bruteforce: O(N2) each pair lookup 
        // search sorted from opposite ends, linear time, compare based on > or < target
        unordered_map<int, int> mp;
        for(int i = 0; i<nums.size(); i++){
            if(mp.count(target-nums[i])) return {mp[target-nums[i]], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};
