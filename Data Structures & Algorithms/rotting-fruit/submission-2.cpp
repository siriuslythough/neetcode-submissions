class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        int dirs[][2]= {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int t = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[j][i]==1) fresh++;
                if(grid[j][i]==2) q.push({j,i});
            }
        }
        // multi-source BFS IMPLEMENTATION 
        while(!q.empty() && fresh>0){
            int lvl_size = q.size();
            while(lvl_size>0){
                pair<int,int> curr = q.front();
                q.pop();
                for(int k = 0; k<4; k++){
                    int y = curr.first + dirs[k][0];
                    int x = curr.second + dirs[k][1];
                    if(y>=0 && x>=0 && y<n && x<m && grid[y][x] == 1){
                        fresh--;
                        grid[y][x] = 2;
                        q.push({y,x});
                    }
                }
                lvl_size--;
            }
            t++;
        }
        if(fresh==0) return t;
        return -1; 
    }
};
