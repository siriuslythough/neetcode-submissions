class Solution {
public:
    int characterReplacement(string s, int k) {
        // use a hashset for each character
        unordered_map<char, int> count;
        int res = 0;
        int l = 0, maxf = 0;
        for(int r = 0; r<s.size(); r++){
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);
            while((r-l+1)-maxf > k){ // key optimization step
                count[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
