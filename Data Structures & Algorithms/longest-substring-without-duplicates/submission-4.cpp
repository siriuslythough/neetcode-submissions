class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // hashset based window condition, O(n) time and space
        int n = s.size();
        int l = 0;
        int maxlen = 0;
        unordered_set<int> lkp;
        for(int r = 0; r<s.size(); r++){
            while(lkp.count(s[r])){
                lkp.erase(s[l]);
                l++;
            }
            lkp.insert(s[r]);
            maxlen = max(maxlen, (int)lkp.size());
        }
        return maxlen;
    }
};
