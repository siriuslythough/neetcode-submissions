class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        for(int i = 0; i < m; i++){
            dfs(0,i,pac,heights);
            dfs(n-1,i,atl,heights);
        }
        for(int j = 0; j < n; j++){
            dfs(j,0,pac,heights);
            dfs(j,m-1,atl,heights);
        }
        vector<vector<int>> ans;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(pac[j][i] && atl[j][i]) ans.push_back({j,i});
            }
        }
        return ans;
    }
private:
    void dfs(int j, int i, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size();
        ocean[j][i] = true;
        int dir[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(int k = 0; k<4; k++){
            int y = j + dir[k][0];
            int x = i + dir[k][1];
            if( y>=0 && x>=0 && y<n && x<m && !ocean[y][x] && heights[y][x]>=heights[j][i]) dfs(y,x,ocean,heights);
        }
    }
};
