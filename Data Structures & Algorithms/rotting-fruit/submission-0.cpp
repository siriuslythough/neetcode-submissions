class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // use multi-source BFS starting from each rotten fruit
        // modify grid in-place to see if the grid entry has been rotten before or not
        // we only track the decrements in fresh to check if the zero fresh fruits state is possible or not, dont need rots
        
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        queue<pair<int,int>> bfs;

        int fresh = 0;
        int mins = 0;

        for(int j = 0; j < grid.size(); j++){
            for(int i = 0; i<grid[0].size(); i++){
                if(grid[j][i] == 2) bfs.push({j,i});
                else if(grid[j][i] == 1) fresh++;
            }
        }

        while(!bfs.empty() && fresh>0){
            int level_size = bfs.size();
            while(level_size>0){
                int row = bfs.front().first;
                int col = bfs.front().second;
                bfs.pop();
                for(int l = 0; l < 4; l++){
                    int j = row + dirs[l][0];
                    int i = col + dirs[l][1];
                    if( j>=0 && i>=0 && j<grid.size() && i<grid[0].size() && grid[j][i]==1 ){
                        grid[j][i] = 2;
                        fresh--;
                        bfs.push({j,i});
                    }
                }
                level_size--;
            }
            mins++;
        }
        if(fresh == 0) return mins;
        return -1;
    }
};
