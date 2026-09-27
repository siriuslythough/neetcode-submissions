class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int a : asteroids){
            if(a>0) st.push_back(a);
            else{
                while(!st.empty() && st.back() > 0 && st.back()<-a) st.pop_back();
            }
            if(!st.empty() && st.back()==-a) st.pop_back();
            else if (st.empty() || st.back()<0) st.push_back(a);
        }
        return st;
    }
};