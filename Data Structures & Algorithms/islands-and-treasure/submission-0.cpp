class Solution {

// This question is meant to teach us Multi-Source BFS.
// Each treasure becomes a source, all at the same time.
// This is optimal because it avoid the repeated search on grids when each empty land cell was being used to run BFS

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> trs;

        for(int j = 0; j<grid.size(); j++){
            for(int i = 0; i<grid[0].size(); i++){
                if(grid[j][i]==0) trs.push({j,i});
            }
        }
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!trs.empty()){
            int jj = trs.front().first;
            int ii = trs.front().second;
            trs.pop();
            for(int l = 0; l<4; l++){
                int j = jj + dirs[l][0];
                int i = ii + dirs[l][1];
                if ( j<0 || i<0 || j>=grid.size() || i>=grid[0].size() || grid[j][i]!=INT_MAX) continue;
                grid[j][i] = grid[jj][ii] + 1;
                trs.push({j,i});
            }
        }
    }
};
