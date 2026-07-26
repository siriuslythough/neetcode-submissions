class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // If at the border. then any that and any connected points will never be surrounded
        // take only inner points, run dfs till you can.
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<char>> copy = board;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                board[j][i] = 'X';
            }
        }
        for(int i = 0; i<m; i++){
            if(copy[0][i]=='O') dfs(0,i,vis,copy,board);
            if(copy[n-1][i]=='O') dfs(n-1,i,vis,copy,board);
        }
        for(int j = 0; j<n; j++){
            if(copy[j][0]=='O') dfs(j,0,vis,copy,board);
            if(copy[j][m-1]=='O') dfs(j,m-1,vis,copy,board);
        }
    }
private:
    void dfs(int j, int i, vector<vector<bool>>& vis, vector<vector<char>>& copy, vector<vector<char>>& board){
        board[j][i] = 'O';
        vis[j][i] = true;
        int n = board.size();
        int m = board[0].size();
        int dir[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(int k = 0; k<4; k++){
            int y = j + dir[k][0];
            int x = i + dir[k][1];
            if(y>=0 && x>=0 && y<n && x<m && !vis[y][x] && copy[y][x] == 'O') dfs(y,x,vis,copy,board);
        }
    }
};
