class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // use an unordered set to store the same word list, but offers faster search for element
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end() || beginWord == endWord) return 0;
        int res = 0;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            res++; // a layer reached
            int len = q.size();
            for(int i = 0; i<len; i++){
                string node = q.front();
                q.pop();
                if(node == endWord) return res;
                // check the differ-by-1 children
                for(int j = 0; j<node.length(); j++){
                    char og = node[j];
                    for(char c = 'a'; c<='z'; c++){ // fixed time search over 26 possibilities
                        if(c==og) continue;
                        node[j] = c; // changed that one index
                        if(words.find(node)!=words.end()){ // a match found in the 
                            q.push(node); // add that as a child for the next level to look at
                            words.erase(node); // since we have seen and returning to it wont ever give the optimal, erase it from the set
                        }
                    }
                    node[j] = og; // get it back as it was too!
                }
            }
        }
        return 0;
    }
};
