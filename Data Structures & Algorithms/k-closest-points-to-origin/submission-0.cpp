// why priority queue:
// insertion & removal time: O(logn)
// retrieval time: O(1)
// size time: O(1)

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        vector<vector<int>> ans;
        for(int i = 0; i<points.size(); i++){
            pq.push({dist(points[i]), points[i]});
            if(pq.size()>k) pq.pop(); // the correct way to maintain size is to pop as soon as the size goes above k     
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
private:
    int dist(vector<int> coord){
        return (coord[0]*coord[0]) + (coord[1]*coord[1]);
    }
};
