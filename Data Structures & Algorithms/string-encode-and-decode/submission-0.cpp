class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        vector<int> sizes;
        string res;
        for(string& s : strs){
            sizes.push_back(s.size());
        }
        for(int sz : sizes){
            res.append(to_string(sz));
            res.push_back(',');
        }
        // store the sizes till here
        res.push_back('#');
        // after # begins the strings fully put together as a unified string
        for(string& s : strs){
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<int> sizes;
        vector<string> res;
        int i = 0; 
        // extract all recorded sizes, read until a comma to get each size
        while(s[i]!='#'){
            int j = i;
            while(s[j]!=','){
                j++;
            }
            sizes.push_back(stoi(s.substr(i,j-i)));
            i = j+1;
        }
        i++; // after the #
        // push back from up till the size to take in
        for(int sz : sizes){
            res.push_back(s.substr(i,sz));
            i+=sz;
        }
        return res;
    }
};
