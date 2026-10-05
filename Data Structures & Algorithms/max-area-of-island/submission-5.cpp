class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        rows = grid.size();
        cols = grid[0].size();
        int maxarea = 0;
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j]==1) maxarea = max(maxarea, dfs(i,j, grid));
            }
        }
        return maxarea;
    }
private:
    int rows, cols;
    int dfs(int i, int j, vector<vector<int>>& grid){
        if( i<0 || j<0 || i>=rows || j>=cols || grid[i][j]!=1 ) return 0;
        grid[i][j] = -1;
        int sum = 1;
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        for(int k = 0; k<4; k++){
            int x = i + drow[k];
            int y = j + dcol[k];
            if( x>=0 && y>=0 && x<rows && y<cols && grid[x][y]==1 ) sum += dfs(x,y,grid);
        }
        return sum;
    }
};
