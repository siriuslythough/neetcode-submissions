class Solution {
public:
    int numIslands(vector<vector<char>>& grid) { 
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int cnt = 0;
        for(int r = 0; r<grid.size(); r++){
            for(int c = 0; c<grid[0].size(); c++){
                if(!vis[r][c] && grid[r][c] == '1'){
                    cnt++;
                    bfs(r, c, vis, grid);
                }
            }
        }
        return cnt;
    }
private:
    void bfs(int row ,int col, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        vis[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row,col});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nbdrow = r + dr[i];
                int nbdcol = c + dc[i];
                if(nbdrow >=0 
                && nbdrow<grid.size() 
                && nbdcol >=0 
                && nbdcol<grid[0].size()
                && grid[nbdrow][nbdcol]=='1'
                && !vis[nbdrow][nbdcol]){
                    vis[nbdrow][nbdcol] = true;
                    q.push({nbdrow,nbdcol});
                }
            }
        }
    }
};
