class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> copy;
        for(int i = 0; i<nums.size(); i++){
            copy.push_back({nums[i],i});
        }
        sort(copy.begin(), copy.end());
        int i = 0;
        int j = copy.size()-1;
        while(i!=j){
            if(copy[i].first+copy[j].first==target){
                break;
            }
            else if (copy[i].first+copy[j].first>target){
                j--;
            }
            else{
                i++;
            }
        }
        int first = copy[i].second;
        int second = copy[j].second;
        return {min(first, second), max(first, second)};
    }
};
