class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // times[i][2] are the edge weights from edge u->v, where u = times[i][0] and v = times[i][1]
        // use Dijkstra's algorithm to get the shortest distance from source to all the nodes in the graph

        // 1. Assemble the weighted adjacency array
        vector<vector<pair<int,int>>> adj(n+1);
        for(int k = 0; k<times.size(); k++) adj[times[k][0]].push_back({times[k][1], times[k][2]});

        // 2. Dijkstra with BFS
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0,k});
        int min_t = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            int n = pq.top().second;
            pq.pop();
            for(auto it : adj[n]){
                int wt = it.second;
                int adjnode = it.first;
                if(d+wt<dist[adjnode]){
                    dist[adjnode] = d + wt;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        for(int i = 1; i<dist.size(); i++){
            min_t = max(min_t, dist[i]);
        }
        if(min_t == INT_MAX) return -1;
        else return min_t;
    }
};
