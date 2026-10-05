class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int idx[26] = {0};
        for(int i = 0; i<order.size(); i++) idx[order[i]-'a']  = i;
        for(int i = 0; i<words.size()-1; i++){
            const string& w1 = words[i], w2 = words[i+1];
            bool matched  = false;
            for(int j = 0; j<w1.size(); j++){
                if(j == w2.size()) return false;
                if(w1[j] != w2[j]){
                    if(idx[w1[j]-'a']>idx[w2[j]-'a']) return false;
                    matched = true;
                    break;
                }
            }
        }
        return true;
    }
};