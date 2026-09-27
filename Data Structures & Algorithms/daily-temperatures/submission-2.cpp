class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // when you start with dp and realize you need more than the just previous state to make a decision, its not a dp
        // its a stack, and you need to temporal data.
        int n = temperatures.size();
        stack<int> st;
        vector<int> nge(n);
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]) st.pop();
            if(st.empty()) nge[i] = 0;
            else nge[i] = st.top()-i;
            st.push(i);
        }
        return nge;
    }
};
