class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // You need to check if the added new edge makes the graph such that,
        // the new edge enables neighbours that have already been visited.
        // This is the BUILD-AS-YOU-GO strategy.
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        vector<vector<int>> seen;
        for(int i = 0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            vector<bool> vis(adj.size()+1, false);
            if(dfs_same(u, v, vis, adj)) return {u,v}; // to check if a path already exists between u and v
                                                       // if so then the edge {u,v} is redundant
            
            // if no such path exists then add edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
private:
    // DFS is now a path-finder between source and target
    bool dfs_same(int curr, int target, vector<bool>& vis, vector<vector<int>>& adj){
        if(curr == target) return true; // BASE CASE: we have reached the target node
        vis[curr] = true;
        for(auto it : adj[curr]){
            if(!vis[it]){
                if(dfs_same(it, target , vis, adj)) return true;
            }
        }
        return false; // checked all neighbours and found nothing 
    }
};
