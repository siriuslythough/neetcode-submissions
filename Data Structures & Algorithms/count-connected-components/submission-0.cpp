class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i,-1, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
private:
    void dfs(int i, int parent, vector<bool>& vis, vector<vector<int>>& adj){
        if(vis[i]) return;
        vis[i] = true;
        for(auto it : adj[i]){
            if(it==parent) continue;
            if(!vis[it]) dfs(it, i, vis, adj);
        }
    }
};
