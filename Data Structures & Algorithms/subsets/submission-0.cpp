class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        formsubset(0, nums, sub, ans);
        return ans;
    }
private:
    void formsubset(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& superset){
        if(i>nums.size()-1){
            superset.push_back(subset);
            return;
        }
        else{
            formsubset(i+1, nums, subset, superset);
            subset.push_back(nums[i]);
            formsubset(i+1, nums, subset, superset);
            subset.pop_back();
        }
    }
};
