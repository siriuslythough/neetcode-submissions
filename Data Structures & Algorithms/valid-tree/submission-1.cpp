class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // DFS on edges list until visited nodes is equal to total 
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);

        if(edges.size()>n-1) return false;

        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        if(!dfs_loop(0, -1, vis, adj)) return false;

        bool res = true;
        for(int k = 0; k<n; k++){
            res = res && vis[k];
        }
        return res;
        
    }
private:
    bool dfs_loop(int i, int parent, vector<bool>& vis, vector<vector<int>>& adj){
        if(vis[i]){ // BASE CASE: if node had already been visited when you reached it
            return false;
        }
        vis[i] = true; // mark node visited
        for(auto it : adj[i]){
            if(it==parent) continue; // undirected edge means parent is also visited by the nbd loop
                                     // you don't want to comment on the nbd being parent, so you continue that iteration
            if(!dfs_loop(it, i, vis, adj)) return false;
        }
        return true;
    }
};
