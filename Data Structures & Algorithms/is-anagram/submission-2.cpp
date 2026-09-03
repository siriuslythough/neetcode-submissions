class Solution {
public:
    bool isAnagram(string s, string t) {
        // bruteforce is O(N2) search for each character and store frequencies
        // anotehr bruteforce is O(N2) search on one and simultaenous look up
        // hashmap data structure for storing frequencies
        // store for one then search and cut short for another
        if(s==t) return true;
        if(s.size()!=t.size()) return false;
        unordered_map<char, int> mp1, mp2;
        for(int i = 0; i< s.size(); i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        if(mp1==mp2) return true;
        return false;
    }
};
