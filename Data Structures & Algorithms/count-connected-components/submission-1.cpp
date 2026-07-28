class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(const auto& vec : edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                iscomp(i, -1, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
private:
    void iscomp(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj){
        if(vis[node]) return;
        vis[node] = true;
        for(int nbd : adj[node]){
            if(nbd == parent) continue;
            iscomp(nbd, node, vis, adj);
        }
    }
};
