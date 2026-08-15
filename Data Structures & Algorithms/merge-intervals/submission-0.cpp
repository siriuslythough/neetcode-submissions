class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(auto& inter : intervals){
            int start = inter[0];
            int end = inter[1];
            int lastend = ans.back()[1]; // to get the last entry in a vector (remember this, new info)
            if(start<=lastend) ans.back()[1] = max(lastend, end);
            else ans.push_back(inter);
        }
        return ans;
    }
};
