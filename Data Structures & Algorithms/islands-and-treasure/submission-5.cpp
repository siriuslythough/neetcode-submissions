class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // BFS is better for this multi-source and nearest distance question. because when the nearest source has already visited a cell, it does not update the distance.
        int rows = grid.size();
        if(rows == 0) return; 
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        const int INF = 2147483647;
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j] == 0) q.push({i,j});
            }
        }
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int sz = q.size();
            for(int f = 0; f<sz; f++){
                int i = q.front().first, j = q.front().second; q.pop();
                for(int k = 0; k<4; k++){
                    int x = i + dr[k];
                    int y = j + dc[k];
                    if(x>=0 && y>=0 && x<rows && y<cols && grid[x][y]==INF){
                        grid[x][y] = grid[i][j] + 1; 
                        q.push({x,y});
                    }
                }
            }
        }
    }
};
