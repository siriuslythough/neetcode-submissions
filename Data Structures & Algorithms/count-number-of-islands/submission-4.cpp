class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int num = 0;
        rows = grid.size();
        cols = grid[0].size();
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j,vis, grid);
                    num ++;
                }
            }
        }
        return num;
    }
private:
    int rows, cols;
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid){
        if( i<0 || j<0 || i>=rows || j>=cols || grid[i][j] == '0') return;
        if(vis[i][j]) return;
        vis[i][j] = true;
        dfs(i+1, j, vis, grid);
        dfs(i-1, j, vis, grid);
        dfs(i, j+1, vis, grid);
        dfs(i, j-1, vis, grid);
    }
};
