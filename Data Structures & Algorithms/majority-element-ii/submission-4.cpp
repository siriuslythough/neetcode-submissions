class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()<3) return nums;
        unordered_map<int, int> f;
        for(int num : nums) f[num]++;
        vector<int> ans;
        for(auto& pair : f){
            if(pair.second>nums.size()/3) ans.push_back(pair.first);
        }
        return ans;
    }
};