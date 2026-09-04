class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tup;
    // A LESSON IN SCALING SOLUTIONS, USING, OF COURSE, RECURSION
    // BASE CASE IS 2, YOU KNOW HOW 3 SUM WAS SOLVED, THATS IT, FIX ONE, FIND K-1 SUM AND SO ON
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        sort(nums.begin(), nums.end());
        ksum(nums, 4, 0, (long long) target);
        return ans;
    }
    void ksum(vector<int>& nums, int k, int start, long long tgt){
        if(k==2){
            int l = start, r = nums.size()-1;
            while(l<r){
                long long sum = (long long) nums[l]+nums[r];
                if(sum<tgt) l++;
                else if(sum>tgt) r--;
                else{
                    tup.push_back(nums[l]); tup.push_back(nums[r]);
                    ans.push_back(tup);
                    tup.pop_back();
                    tup.pop_back();
                    l++; r--;
                    while(l<r && nums[l] == nums[l-1]) l++;
                    while(l<r && nums[r] == nums[r+1]) r--;
                }
            } 
            return;
        }
        for(int i = start; i<nums.size()-k+1; i++){
            if(i>start && nums[i] == nums[i-1]) continue;
            tup.push_back(nums[i]);
            ksum(nums, k-1, i+1, tgt-nums[i]);
            tup.pop_back();
        }
    }
};