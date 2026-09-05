class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // bruteforce, single position shifting code, done nk times, O(NK) time, O(1) space
        int n = nums.size();
        for(int l = 0; l<k; l++){
            int rot = nums[n-1];
            for(int i = n-1; i>=1; i--){
                int temp = nums[i-1];
                nums[i] = temp;
            }
            nums[0] = rot;
        }
    }
};