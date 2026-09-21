class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for(int i : asteroids){ 
            bool destroyed = false;
            while(!st.empty() && st.top()>0 && i<0){
                if(st.top()+i==0){st.pop(); destroyed = true; break;}
                else if (st.top()+i<0) st.pop();

                else {destroyed = true; break;}
            }
            if(!destroyed) st.push(i);
        }
        while(!st.empty()){
            ans.push_back(st.top()); 
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};