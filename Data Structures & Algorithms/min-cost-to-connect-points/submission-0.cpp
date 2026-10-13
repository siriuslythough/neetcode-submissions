class DSU{
    vector<int> rank, parent;
public:
    DSU(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        for(int i = 0; i<n; i++) parent[i] = i;
    }
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    bool unionbysize(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv) return false;
        if(rank[pu]>rank[pv]){
            parent[pv] = pu;
            rank[pu]+=rank[pv];
        }
        else{
            parent[pu] = pv;
            rank[pv]+=rank[pu];
        }
        return true;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        vector<array<int, 3>> edges;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int res = 0;
        for(auto& [dist, u, v] : edges){
            if(dsu.unionbysize(u,v)) res+=dist;
        }
        return res;
    }
};
