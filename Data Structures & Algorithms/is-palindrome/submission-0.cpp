class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l<r){
            while(l<r && !isalphanum(s[l])) l++;
            while(l<r && !isalphanum(s[r])) r--;
            if(tolower(s[l])!=tolower(s[r])){
                return false;
            }
            l++; r--;
        }
        return true;
    }
    bool isalphanum(char c){
        return (c>='A' && c<='Z' || c>='a' && c<'z' || c>='0' && c<='9');
    }
};
