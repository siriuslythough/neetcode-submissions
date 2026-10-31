class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefproduct(nums.size(), 1);
        vector<int> suffproduct(nums.size(), 1);
        for(int i = 1; i<nums.size(); i++){
            prefproduct[i]=prefproduct[i-1]*nums[i-1];
            suffproduct[nums.size()-i-1]= suffproduct[nums.size()-i]*nums[nums.size()-i];
        }
        vector<int> res;
        for(int i = 0; i<nums.size(); i++){
            res.push_back(prefproduct[i]*suffproduct[i]);
        }
        return res;
    }
};
