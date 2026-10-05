class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        rows = grid.size();
        cols = grid[0].size();
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,grid);
                    num ++;
                }
            }
        }
        return num;
    }
private:
    int rows, cols;
    void dfs(int i, int j, vector<vector<char>>& grid){
        if( i<0 || j<0 || i>=rows || j>=cols || grid[i][j]!= '1') return;
        grid[i][j] = 'V';
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }
};
