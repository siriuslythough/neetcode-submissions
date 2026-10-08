class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0; // given source
        pq.push({0,0,0});
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int diff = curr[0], r = curr[1], c = curr[2];
            if(r==rows-1 && c == cols-1) return diff; // given destination, stop when reach here, cause dont need the distance from src to each point
            if(dist[r][c]<diff) continue;
            for(auto& dir : dir){
                int x = r + dir[0], y = c + dir[1];
                if(x<0 || y<0 || x>=rows || y>=cols) continue;
                int newdiff = max(diff, abs(heights[r][c]-heights[x][y]));
                if(newdiff<dist[x][y]){
                    dist[x][y] = newdiff;
                    pq.push({newdiff, x, y});
                }
            }
        }
        return 0;
    }
};