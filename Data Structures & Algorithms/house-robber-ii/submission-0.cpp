class Solution {
public:
    int rob(vector<int>& nums) {
        // solve this by breaking it down into two problems on linear arrays
        // first: rob houses excluding the first one
        // second: rob houses excluding the second one
        vector<int> n_excludefirst(nums.begin()+1, nums.end());
        vector<int> n_excludelast(nums.begin(), nums.end()-1);
        return max(nums[0], max(helper(n_excludefirst), helper(n_excludelast)));
        // the max(nums[0], max(...)) is done for the case when nums has only one element
    }
private:
    int helper(vector<int>& nums){
        int rob2 = 0;
        int rob1 = 0;
        int temp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            temp = max(nums[i]+rob2, rob1);
            rob2 = rob1;
            rob1 = temp; 
        }
        return rob1;
    }
};
