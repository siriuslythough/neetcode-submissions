class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // given a weighted graph, constructed the adjacency
        vector<vector<pair<int, int>>> adj(n+1);
        for(const auto& edge : times) adj[edge[0]].push_back({edge[1], edge[2]}); // store {node, wt}
        vector<int> d(n+1, INT_MAX);
        d[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        pq.push({d[k], k});
        int t = 0;
        while(!pq.empty()){
            int sz = pq.size();
            for(int i = 0; i<sz; i++){
                auto node = pq.top();
                int tku = node.first, u = node.second; 
                pq.pop();
                if(tku>d[u]) continue;
                for(auto& c : adj[u]){
                    int v = c.first, wt = c.second;
                    if(tku + wt < d[v]){
                        d[v] = tku + wt;
                        pq.push({d[v], v});
                    }
                }
            }
        }
        for(int i = 1; i<=n; i++){
            if(d[i] == INT_MAX) return -1;
            t = max(t, d[i]);
        }
        return t;
    }
};
