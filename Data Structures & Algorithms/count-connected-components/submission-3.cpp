class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // just count the number of dfs calls to make
        // and dfs has to take parent as a parameter for unidirected graph traversal
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, -1, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
private:
    void dfs(int i, int p, vector<bool>& vis, vector<vector<int>> adj){
        if(vis[i]) return;
        vis[i] = true;
        for(int c : adj[i]){
            if(c == p) continue;
            dfs(c, i, vis, adj);
        }
    }
};
