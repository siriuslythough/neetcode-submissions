class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // a hash map to store for each position how many earlier position have a prefix sum of currprefixsum - k 
        int res = 0, cursum = 0; 
        unordered_map<int, int> prefixsums;
        prefixsums[0] = 1;
        for(int num : nums){
            cursum += num;
            int diff = cursum - k;
            res += prefixsums[diff];
            prefixsums[cursum]++;
        }
        return res;
    }
};