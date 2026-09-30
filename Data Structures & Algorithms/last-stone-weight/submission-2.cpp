class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // "at each step", "heaviest" -> repeated maximum
        // two heaps of stones
        priority_queue<int> h;
        for(int i : stones) h.push(i);
        while(h.size()>1){
            int x = h.top(); h.pop(); 
            int y = h.top(); h.pop();
            if(x<y) h.push(y-x);
            else if(x>y) h.push(x-y);
            else continue;
        }
        return h.size()==1?h.top():0;
    }
};
