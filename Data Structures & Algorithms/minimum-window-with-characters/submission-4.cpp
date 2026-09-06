class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp1, mp2;
        for(char& i : t){
            mp1[i]++;
        }
        int l = 0, r = 0;
        int i = 1e9, j = 1e9;
        int min_len = 1e9;
        // helper function to check if window contains all the target characters, this is the bottleneck that increases the complexity
        auto isvalid = [&](){
            for(auto& pair : mp1){
                if(mp2[pair.first]<pair.second) return false;
            }
            return true;
        };

        while(r<s.size()){
            mp2[s[r]]++; // include right character into the map count

            // shrink window from the left while it contains all the targets
            while(isvalid()){
                if(r-l+1<min_len){
                    min_len = r-l+1;
                    i = l;
                    j = r;
                }
                mp2[s[l]]--;
                l++;
            }
            r++; // advance pointer to expand the window after all is done
        }
        return (i==1e9 || j==1e9)?"":s.substr(i,j-i+1);
    }
};
