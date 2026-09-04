class Solution {
public:
    bool validPalindrome(string s) {
        // as soon as counter over, break and return
        int l = 0, r = s.size()-1;
        bool skip1 = false;
        while(l<r){
            while(l<r && !alphanum(s[r])) r--;
            while(l<r && !alphanum(s[l])) l++;
            if(!skip1 && s[l]!=s[r]){ // need to call the function only one because at most one skip. 
                                      // otherwise this is like one layer deep recursion
                return ispalindrome(s,l+1,r) || ispalindrome(s,l,r-1);
            }
            l++; r--;
        }
        return true;
    }
    bool ispalindrome(const string& s, int l, int r){
        while(l<r){
            while(l<r && !alphanum(s[r])) r--;
            while(l<r && !alphanum(s[l])) l++;
            if(s[l]!=s[r]) return false;
            l++; r--;
        }
        return true;
    }
    bool alphanum(char c){
        return ( c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9');
    }
};