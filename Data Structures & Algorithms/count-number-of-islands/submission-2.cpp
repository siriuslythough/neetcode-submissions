class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        for(int j = 0; j<n; j++){
            for(int i = 0; i<m; i++){
                if(!vis[j][i] && grid[j][i]=='1'){
                    dfs(j,i,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
private:
    void dfs(int j, int i, vector<vector<bool>>& vis, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(j>=n || i>=m || j<0 || i<0 || grid[j][i]=='0' || vis[j][i]) return;
        vis[j][i] = true;
        dfs(j+1, i, vis, grid);
        dfs(j-1, i, vis, grid);
        dfs(j, i+1, vis, grid);
        dfs(j, i-1, vis, grid);
    }
};
