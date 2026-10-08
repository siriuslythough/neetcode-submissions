class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // as soon as cycle is detected, remove the last edge, that is, parent->child edge
        vector<vector<int>> adj(edges.size()+1);
        for(const auto& e : edges){
            int u  = e[0], v = e[1];
            vector<bool> vis(edges.size()+1, false);
            if(haspath(u, v, vis, adj)) return e;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
private:
    bool haspath(int cur, int tgt,  vector<bool>& vis, const vector<vector<int>>& adj){
        if(cur == tgt) return true;
        vis[cur] = true;
        for(int c : adj[cur]){
            if(!vis[c]){
                if(haspath(c, tgt, vis, adj)) return true;
            }
        }
        return false;
    }
};
