class Solution {
public:
    string minWindow(string s, string t) {
        int minlen = INT_MAX;
        int l  = -1; //storing start position
        int count = 0;
        vector<int> hm(256,0); //initialize the hashmap to store 256 characters in ASCII
        for(int j = 0; j<t.size(); j++) hm[t[j]]++; //initialize hash map with frequency counts of chars in t
        int i = 0; //left pointer
        for(int k = 0; k<s.size(); k++){ //k is right pointer
            if(hm[s[k]]>0){ 
            //if the element we want to add was already sen by hashmap, 
            //then first increase count of the elements of t that you have seen.
            //you dont increase the count if that element is in negative frequency,
            //because we have seen the nmuber of time sit appear in t, new ones are not there in t
                count++;
            }
            hm[s[k]]--; //track how many times have seen s[k] character
            while(count == t.size()){ //seen all? This is the VALIDATION CONDITION
                if(k-i+1<minlen){ 
                    minlen = k-i+1;
                    l = i;
                }
                hm[s[i]]++; //re-introduce the character leaving the left end of the window
                if(hm[s[i]] > 0){
                    count--; 
                }
                i++;
            }
        }
        if(l==-1) return "";
        return s.substr(l,minlen);
    }
};
