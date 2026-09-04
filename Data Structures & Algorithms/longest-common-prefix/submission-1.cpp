class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans;
        for(int i = 0; i<strs[0].size(); i++){
            char ref = strs[0][i]; 
            for(int j = 1; j<strs.size(); j++){
                if(strs[j][i] != ref) return ans;
            }
            ans += ref;
        }
        return ans;
    }
};