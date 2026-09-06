class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxel;
        // need to calculate the max to get started one, then compare the one inner, the max, and the upcoming element??
        int l = 0, r = 0;
        // initialize the window
        int wmax = nums[r];
        for(int i = 1; i<k; i++) wmax = max(wmax, nums[i]);
        maxel.push_back(wmax);

        // start the sliding window from here:
        for(int i = k; i<nums.size(); i++){
            int prev_l = nums[i-k]; // falling out
            int new_r = nums[i]; //  coming in
            if(new_r>=wmax){
                wmax = new_r;
            }else if(prev_l == wmax){
                wmax = nums[i-k+1];
                for(int j = i-k+2; j<=i; j++){
                    wmax = max(wmax, nums[j]);
                }
            }
            maxel.push_back(wmax); 
        }
        return maxel;
    }
};
