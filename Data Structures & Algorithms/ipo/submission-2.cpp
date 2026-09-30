class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq; // only store the rising capital in the prirority queue, dont need the capital from there, that was only needed to make decision to put into pq
        int n = profits.size();
        vector<pair<int, int>> vec;
        for(int i = 0; i<n; i++) vec.push_back({capital[i], profits[i]});
        sort(vec.begin(), vec.end());
        int runcap = w;
        int i = 0;
        for(int step = 0; step<k; step++){ //  perform up to k project selections
            // push all affordable projects into the maxheap for profits
            while(i<n && vec[i].first <= runcap){pq.push({vec[i].second}); i++;}
            if(pq.empty()) break; //  if no projects can be afforded, break, cause you aint getting any capital to buy more projects
            runcap += pq.top(); // execute the most profitable project 
            pq.pop();
        }
        return runcap;
    }
};