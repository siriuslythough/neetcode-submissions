class MinStack {
    stack <long long> st;
    long long mini;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{
            if(val>mini) st.push(val);
            else{
                st.push(2LL*val-mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        else{
            if(st.top()<mini){
                mini = 2LL*mini - st.top();
            }
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        else{
            if(mini>st.top()) return mini;
            return st.top();
        }
    }
    
    int getMin() {
        return mini;
        
    }
};
