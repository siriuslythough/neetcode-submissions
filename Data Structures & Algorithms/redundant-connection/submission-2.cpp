class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        // construct graph on the way by using incoming edges,
        // and check if the graph that has been created til now has 
        // any path already going from u to v, where [u->v] is an edge you just saw
        for(const auto& vec : edges){
            vector<bool> vis(n+1, false);
            if (path_exists(vec[0], vec[1], vis, adj)) return {vec[0],vec[1]};
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        return {};
    }
private:
    bool path_exists(int node, int target, vector<bool>& vis, vector<vector<int>>& adj){
        if(node == target) return true;
        vis[node] = true;
        for(int nbd : adj[node]){
            if(!vis[nbd]){
                if(path_exists(nbd, target, vis, adj)) return true;
            }
        }
        return false;
    }
};
