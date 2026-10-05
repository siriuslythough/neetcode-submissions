class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // number of adjacent water or outside cells is the perimeter
        this->grid = grid;
        rows = grid.size();
        cols = grid[0].size();
        vis = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for(int i = 0; i< rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j] == 1) return dfs(i,j); // there is only one island
            }
        }
        return 0;
    }
private:
    vector<vector<int>> grid;
    vector<vector<bool>> vis;
    int rows, cols;
    int dfs(int i, int j){
        if(i<0 || j < 0 || i>=rows || j>=cols || grid[i][j] == 0) return 1;
        if(vis[i][j]) return 0;
        vis[i][j] = true;
        return dfs(i+1, j) + dfs(i-1, j) + dfs(i,j+1) + dfs(i,j-1);
    }
};