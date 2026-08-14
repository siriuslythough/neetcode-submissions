class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<bool>> visit(n, vector<bool>(n,false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<> > pq;
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // each cell height is the earliest time you are allowed to stand on it. Got that one kinda. was lost in the edge weights issue
        // total time of a path is not the sum - it’s the maximum height you ever step on (because water must rise to that max). you swim all that you can in one go as long as you get water in front of you

        visit[0][0] = true;
        pq.emplace(grid[0][0], 0, 0);

        while(!pq.empty()){
            auto [curr_t, i, j] = pq.top();
            pq.pop();
            if(i == n-1 && j == n-1) return curr_t;
            for(const auto& dir : dirs){
                int x = i + dir.first;
                int y = j + dir.second;
                if(x<0 || y<0 || x>=n || y>=n || visit[x][y]) continue;
                visit[x][y] = true;
                pq.emplace(max(curr_t, grid[x][y]), x, y);
            }
        }

        return -1;
    }
};
