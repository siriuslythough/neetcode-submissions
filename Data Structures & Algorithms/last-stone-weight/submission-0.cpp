class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0; i<stones.size(); i++){
            pq.push(stones[i]);
        }
        int h1, h2;
        while(pq.size()>1){
            h1 = pq.top();
            pq.pop();
            h2 = pq.top();
            pq.pop();
            if (h1!=h2) pq.push(h1-h2);
        }
        if(pq.size()) return pq.top();
        return 0;
    }
};
