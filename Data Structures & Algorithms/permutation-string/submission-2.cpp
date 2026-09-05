class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // fixed size window thank god.
        // create a hashmap for s1, fill it, then reduce the count each time you see it in a window, undo that reduction when window moves.
        unordered_map<char, int> mp1;
        for(int i = 0; i<s1.size(); i++){
            mp1[s1[i]]++;
        }
        int k = mp1.size();
        for(int i = 0; i<s2.size(); i++){
            unordered_map<char, int> mp2;
            int cur = 0;
            for(int j = i; j<s2.length(); j++){
                mp2[s2[j]]++;
                if(mp1[s2[j]]<mp2[s2[j]]) break;
                if(mp1[s2[j]]==mp2[s2[j]]) cur++;
                if(cur==k) return true;
            }
        }
        return false;
    }
};
