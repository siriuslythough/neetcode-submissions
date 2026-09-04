class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i1 = 0,i2 = 0; 
        int n1 = word1.size(), n2 = word2.size();
        string s;
        while(i1<n1 || i2<n2){
            if(i1<n1) s+=word1[i1];
            if(i2<n2) s+=word2[i2];
            i1++;i2++;
        }
        return s;
    }
};