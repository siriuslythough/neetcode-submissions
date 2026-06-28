class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> vis (grid.size(), vector<bool> (grid[0].size(), false));
        int maxarea = 0;
        int area = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(!vis[i][j] && grid[i][j]==1){
                    area = bfs_area(i,j,grid,vis);
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;
    }
private:
    int bfs_area(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        int area = 1;
        vis[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i,j});
        int di[] = {1,0,-1,0};
        int dj[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k = 0; k<4; k++){
                int nbd_i = r+di[k];
                int nbd_j = c+dj[k];
                if (nbd_i>=0 &&
                    nbd_j>=0 &&
                    nbd_i<grid.size() &&
                    nbd_j<grid[0].size() &&
                    !vis[nbd_i][nbd_j] &&
                    grid[nbd_i][nbd_j] == 1){
                        vis[nbd_i][nbd_j] = true;
                        q.push({nbd_i, nbd_j});
                        area++;
                    }
            } 
        }
        return area;
    }
};
