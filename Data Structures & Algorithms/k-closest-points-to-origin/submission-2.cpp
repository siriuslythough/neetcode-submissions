class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> h;
        vector<vector<int>> ans;
        for(const auto& i : points){
            h.push({d(i),{i}});
            if(h.size()>k) h.pop();
        }
        while(!h.empty()){ans.push_back(h.top().second); h.pop();}
        return ans;
    }
private: 
    int d(const vector<int>& point){
        return point[0]*point[0] + point[1]*point[1];
    }
};
