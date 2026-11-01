class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), l = 0, r = 0, len = 0;
        unordered_set<char> st;
        while(r<n){
            while(st.find(s[r])!=st.end()) {st.erase(s[l]); l++;}
            st.insert(s[r]);
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};
