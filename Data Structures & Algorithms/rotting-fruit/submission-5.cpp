class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // this is a bfs problem, for each layer that you traverse increment the minute
        // multisource again, each rotten banana is the source
        queue<pair<int,int>> q;
        int fresh = 0;
        int rows = grid.size(), cols = grid[0].size();
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j] != 0) fresh++;
                if(grid[i][j] == 2) {q.push({i,j}); fresh--;}
            }
        }
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};
        int time = 0;
        while(!q.empty() && fresh>0){
            int sz = q.size();
            for(int f = 0; f<sz; f++){
                int i = q.front().first, j = q.front().second; q.pop();
                for(int k = 0; k<4; k++){
                    int x = i + dr[k];
                    int y = j + dc[k];
                    if(x>=0 && y>=0 && x<rows && y<cols && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x,y});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh==0?time:-1;
    }
};
