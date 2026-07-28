class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // to check if its a valid "tree", it has to be a DAG with no node visited again (no cycles)
        // it's undirected so check for the parent to not be included as a neighbour
        // it should also have a single component
        vector<vector<int>> adj(n);
        for(const auto& vec : edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        vector<bool> vis(n, false);
        if(hascycle(0, -1, vis, adj)) return false; // you don't have an inherent structural root!!!
        // to check for connected components
        bool res = true;
        for(int i = 0; i<n; i++){
            res = res && vis[i];
        }
        return res;
    }
private:
    bool hascycle(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj){
        if(vis[node]) return true;
        vis[node]=true;
        for(int i : adj[node]){
            if(i == parent) continue;
            if(hascycle(i, node, vis, adj)) return true;
        }
        return false;
    }
};
