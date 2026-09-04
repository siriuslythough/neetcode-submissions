class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // two sum but the target is changing, in fact its -num[k]
        // also can sort because ORDER DOES NOT MATTER!
        // ... when order matters you have to track the indices or just not sort
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue; // the "non" in the non-decreasing case
            int l = i+1, r = n-1;
            while(l<r){
                int tgt = nums[l]+nums[r]+nums[i];
                if(tgt>0) r--;
                else if (tgt<0) l++;
                else {
                   ans.push_back({nums[i], nums[l], nums[r]});
                   l++;
                   r--;
                   while(l<r && nums[l] == nums[l-1]) l++; 
                }
            }
        }
        return ans;
    }
};
