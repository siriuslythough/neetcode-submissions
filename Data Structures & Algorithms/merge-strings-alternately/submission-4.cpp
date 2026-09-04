class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if(word1.size()<word2.size()) return mergeAltSameLen(word1, word2)+word2.substr(word1.size()); 
        if(word1.size()>word2.size()) return mergeAltSameLen(word1, word2)+word1.substr(word2.size()); 
        return mergeAltSameLen(word1, word2);
    }
    string mergeAltSameLen(string& a, string& b){
        string s;
        for(int i = 0; i<min(a.size(), b.size()); i++){s+=a[i]; s+=b[i];}
        return s;
    }
};