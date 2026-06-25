class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>> root_locs;
        for(int j = 0; j<board.size(); j++){
            for(int i = 0; i<board[0].size(); i++){
                if(board[j][i]==word[0]){
                    if (search_neighbour(board, word, j, i, 0)) {
                        return true; // Fast exit if found
                    }
                }
            }
        }
        return false;
    }

// In SDE interviews, interviewers don't want you to use an unordered_set or an extra seen matrix at all. 
// It wastes $O(N \times M)$ space.
// Instead, when you visit a cell, you temporarily mutate the board (e.g., change the character to #) 
// to mark it as visited. After checking all 4 directions, you change it back 
// to the original character (this is the backtracking step!). 
// This restricts your space complexity strictly to the recursion stack.

private: // pass the baord and string again to avoid copying from memory
    bool search_neighbour(vector<vector<char>>& board,string& word, int y, int x, int pos){
        // BASE CASE 1: FOUND ALL CHARACTERS, OBVIOUSLY YOU FOUND ALL OF THEM, IN FACT COUNTER HAS REACHED AHEAD OF SIZE
        if(pos == word.size()) return true; // you have moved till here only because you found all letters of the key

        // BASE CASE 2: OUT OF BOUNDS OR WORD NOT IN THIS POSITION
        if(y>=board.size() || x>=board[0].size() || x<0 || y<0 || board[y][x]!=word[pos]) return false;

        // if none of the above base cases were met, then this position is the valid case of you fiding a character
        // mark it with a special character that serves as the memory of your trail
        char temp = board[y][x]; // store the orginal value for replacement later
        board[y][x] = '#';;

        bool will_see_ahead = search_neighbour(board, word, y+1, x, pos + 1) || 
                    search_neighbour(board, word, y-1, x, pos + 1) ||
                    search_neighbour(board, word, y, x+1, pos + 1) ||
                    search_neighbour(board, word, y, x-1, pos + 1);
        board[y][x] = temp; // restore the trail
        return will_see_ahead;
    }
};
