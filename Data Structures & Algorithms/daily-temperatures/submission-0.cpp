class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> nge(n);
        for(int i = n-1; i>=0; i--){
            // pop all that are cooler than current
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]) st.pop();
            if (st.empty()) nge[i] = 0;
            else nge[i] = st.top()-i;
            st.push(i); // always push current index after checking
        }
        return nge;
    }
};
