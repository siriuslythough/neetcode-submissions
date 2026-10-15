class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // choose the sources which need minimum time in bfs
        vector<vector<int>> adj(n);
        for(auto& edge : edges){adj[edge[1]].push_back(edge[0]); adj[edge[0]].push_back(edge[1]);}
        vector<int> dist(n,0);
        int minh = INT_MAX;
        for(int k = 0; k<n; k++){
            queue<int> q;
            vector<int> vis(n, false);
            vis[k] = true;
            int h = 0;
            q.push(k);
            while(!q.empty()){
                int sz = q.size();
                for(int j = 0; j<sz; j++){
                    int node = q.front();
                    q.pop();
                    for(int nbd : adj[node]){
                        if(!vis[nbd]) {
                            vis[nbd] = true;
                            q.push(nbd);
                        }
                    }
                }
                if(!q.empty()) h++;
            }
            dist[k] = h;
            minh = min(minh, h);
        }
        vector<int> res;
        for(int i = 0; i<n; i++){
            if(dist[i]==minh) res.push_back(i);
        }
        return res;
    }
};