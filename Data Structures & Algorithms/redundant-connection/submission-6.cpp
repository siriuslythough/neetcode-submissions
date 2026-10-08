class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); 
        vector<int> parent(n+1), size(n+1, 1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
        for(const auto& edge : edges){
            if(!setunion(parent, size, edge[0], edge[1])) return vector<int>{edge[0], edge[1]};
        }
        return {};
    }
private:
    int findparent(int u, vector<int>& parent){
        if(u==parent[u]) return u;
        return parent[u] = findparent(parent[u], parent);
    }
    bool setunion(vector<int>& parent, vector<int>& size, int u, int v){
        int ulp_u = findparent(u, parent);
        int ulp_v = findparent(v, parent);
        if(ulp_u == ulp_v) return false; //  already unionized
        // basically is the edge nodes have same ultimate parent then it means they make a cycle
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        return true;
    }
};

