class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacirch(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlarch(heights.size(), vector<bool>(heights[0].size(), false));
        // Start DFS from the edges, touching the ocean
        for(int j = 0; j<heights.size(); j++){
            paci_dfs(j,0,heights,pacirch); // left border (pacific)
            atla_dfs(j,heights[0].size()-1, heights, atlarch); // right border (atlantic)
        }
        for(int i = 0; i<heights[0].size(); i++){
            paci_dfs(0,i,heights,pacirch); // top border (pacific)
            atla_dfs(heights.size()-1, i, heights, atlarch); // bottom border (atlantic)
        }
        vector<vector<int>> ans;
        for(int j = 0; j<heights.size(); j++){
            for(int i = 0; i<heights[0].size(); i++){
                if(pacirch[j][i]==true && atlarch[j][i]==true) ans.push_back({j,i}); 
            }
        }
        return ans;
    }
private:
    void paci_dfs(int j, int i, 
            vector<vector<int>>& heights,  
            vector<vector<bool>>& pacirch){
        pacirch[j][i]=true;
        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        for (int k = 0; k < 4; k++){
            int nr = j + dirs[k][0];
            int nc = i + dirs[k][1];
            if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() 
                && pacirch[nr][nc]!=true 
                && heights[nr][nc]>=heights[j][i]){
                    paci_dfs(nr, nc, heights, pacirch);
            }
        }
    }
    void atla_dfs(int j, int i, 
            vector<vector<int>>& heights,  
            vector<vector<bool>>& atlarch){
        atlarch[j][i]=true;
        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        for (int k = 0; k < 4; k++){
            int nr = j + dirs[k][0];
            int nc = i + dirs[k][1];
            if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() 
                && atlarch[nr][nc]!=true 
                && heights[nr][nc]>=heights[j][i]){
                    atla_dfs(nr, nc, heights, atlarch);
            }
        }
    }
};
