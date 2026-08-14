class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // construct weighted directed graph from flights
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& trip : flights){
            adj[trip[0]].push_back({trip[1], trip[2]});
        }
        // There will be no negative weights. Its a single source problem
        // Run Dijkstra's algo. But you need to check if you have gone beyond the depth of k.

        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.emplace(0, src, -1);

        while(!pq.empty()){
            auto [d, i, stp] = pq.top();
            pq.pop();
            
            if(i==dst) return d;
            if(stp == k || dist[i][stp+1]<d) continue; // reached k stops already in that minheap retrieval or if memo distance is lesser than what we are seeing from minheap retrieval
            for(auto& [j, wt] : adj[i]){
                if(d+wt<dist[j][stp+2]){
                    dist[j][stp+2] = d + wt;
                    pq.emplace(dist[j][stp+2], j, stp + 1);
                }
            }
        }
        return -1;
    }
};
