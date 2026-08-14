class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int, int>> visit;
        priority_queue<vector<int>, vector<vector<int>>, greater<> > pq;
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        // each cell height is the earliest time yopu are allowed to stand on it. Got that one kinda. was lost in the edge weights issue
        //total time of a path is not the sum — it’s the maximum height you ever step on (because water must rise to that max). you swim all that you can in one go as long as you get water in front of you
        visit.insert({0,0});
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int curr_t = curr[0], i = curr[1], j = curr[2];
            if(i == n-1 && j == n-1) return curr_t;
            for(const auto& dir : dirs){
                int x = i + dir[0];
                int y = j + dir[1];
                if(x<0 || y<0 || x>=n || y>=n || visit.count({x,y})) continue;
                visit.insert({x,y});
                pq.push({max(curr_t, grid[x][y]), x, y});
            }

        }
        return n*n;
    }
};
