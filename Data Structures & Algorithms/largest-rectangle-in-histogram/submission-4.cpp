class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // for each h[i] need the index of the next and previous smaller index to form the largest rectangle including that height.
        // so get the psei and nsei; avoid duplicate heights by making one of them allowing equal heights and other is strict
        // yes its possible that this height could use the smaller height blocks to form a rectangle, but that would be captured when we are solving the subproblem for the smaller height blocks.
        int n = heights.size();
        stack<int> st;
        vector<int> psei(n), nsei(n);
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[i]<heights[st.top()]) st.pop();
            if(!st.empty()) psei[i] = st.top();
            else psei[i] = -1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && heights[i]<=heights[st.top()]) st.pop();
            if(!st.empty()) nsei[i] = st.top();
            else nsei[i] = n;
            st.push(i);
        }
        int maxarea = 0;
        for(int i = 0; i<n; i++){
            maxarea = max(maxarea, heights[i]*(nsei[i]-psei[i]-1));
        }
        return maxarea;
    }
};
