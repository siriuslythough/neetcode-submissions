class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> keep(nums.size(), false);
        vector<int> perm;
        bt(keep, perm, nums);
        return ans;
    }
private:
    void bt(vector<bool>& keep, vector<int>& perm, vector<int>& nums){
        if(perm.size()==nums.size()){
            ans.push_back(perm);
            return;
        }
        for(int i = 0; i<nums.size(); i++){
            if(!keep[i]){
                perm.push_back(nums[i]);
                keep[i] = true;
                bt(keep, perm, nums);
                perm.pop_back();
                keep[i] = false;
            }
        }
    }
};
