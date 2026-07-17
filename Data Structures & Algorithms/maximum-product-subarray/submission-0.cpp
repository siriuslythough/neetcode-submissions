class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0];
        for(int i = 0; i<nums.size(); i++){
            int curr = nums[i];
            maxprod = max(curr, maxprod);
            for(int j = i+1; j<nums.size(); j++){
                curr*=nums[j];
                maxprod = max(curr, maxprod);
            }
        }
        return maxprod;
    }
};
