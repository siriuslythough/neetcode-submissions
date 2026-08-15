class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(auto& inter : intervals){
            int start = inter[0];
            int end = inter[1];
            int lastend = ans.back()[1];
            if(start<=lastend) ans.back()[1] = max(end, lastend);
            else ans.push_back(inter);
        }
        return ans;
    }
};
