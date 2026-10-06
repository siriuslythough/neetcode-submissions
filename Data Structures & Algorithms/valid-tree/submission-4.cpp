class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // A tree has a DAG, so use dfs with visited to treat it as a directed graph. so do not
        vector<vector<int>> adj(n);
        for(auto uv : edges){
            adj[uv[0]].push_back(uv[1]);
            adj[uv[1]].push_back(uv[0]);
        }
        vector<bool> vis(n, false);
        // check for isolated connected components
        if(!dfs(0, -1, vis, adj)) return false;
        bool res = true;
        for(int j = 0; j<n; j++){
            res = res && vis[j];
        }
        return res;
    }
private:
    bool dfs(int i, int parent, vector<bool>& vis, vector<vector<int>>& adj){
        if(vis[i]) return false;
        vis[i] = true;
        for(int nbd : adj[i]){
            if(nbd == parent) continue;
            if(!dfs(nbd, i, vis, adj)) return false;
        }
        return true;
    }
};
