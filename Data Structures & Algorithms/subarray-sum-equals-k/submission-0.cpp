class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute force, two pointers, sliding window, fix i, read ahead with j till the end
        // then try this with 1d dp from the back
        int cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            int sum = 0;
            for(int j = i; j<nums.size(); j++){
                sum += nums[j];
                if(sum == k) cnt++;
            }
        }
        return cnt;
    }
};