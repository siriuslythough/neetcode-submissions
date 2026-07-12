class Solution {
    int ROWS, COLS;
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();
        for(int r = 0; r<ROWS; r++){
            if(board[r][0]=='O') capture(r,0,board);
            if(board[r][COLS-1]=='O') capture(r,COLS-1,board);
        }
        for(int c = 0; c<COLS; c++){
            if(board[0][c]=='O') capture(0,c,board);
            if(board[ROWS-1][c]=='O') capture(ROWS-1,c,board);
        }
        for(int r = 0; r<ROWS; r++){
            for(int c = 0; c<COLS; c++){
                if(board[r][c]=='O') board[r][c] = 'X';
                else if(board[r][c]=='T') board[r][c] = 'O';
            }
        }
    }
private:
    void capture(int r, int c, vector<vector<char>>& board){
        if( r<0 || c<0 || r>=ROWS || c>=COLS || board[r][c]!= 'O') return;
        board[r][c] = 'T';
        capture(r,c-1,board);
        capture(r,c+1,board);
        capture(r-1,c,board);
        capture(r+1,c,board);
    }
};
