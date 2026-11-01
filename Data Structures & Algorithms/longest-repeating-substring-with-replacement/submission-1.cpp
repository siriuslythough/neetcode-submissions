class Solution {
public:
    int characterReplacement(string s, int k) {
        // use a hashset for each character
        unordered_map<char, int> count;
        int res = 0;
        int l = 0, maxf = 0;
        for(int r = 0; r<s.size(); r++){
            count[s[r]]++;
            // we use maxf because in that case need to make least number of replacements for the less frequents
            maxf = max(maxf, count[s[r]]);
            while((r-l+1)-maxf > k){ // key optimization step
            // maxf stays same and until that character s[r] remains the most frequent,
            // squeeze window until small enough that the to-be-replaced are <k
                count[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
