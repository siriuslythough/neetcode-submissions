class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int n = s.size()-1;
        int temp;
        for(int i = 0; i<=n/2; i++){
            temp = s[i];
            s[i] = s[n-i];
            s[n-i] = temp;
        }
    }
};