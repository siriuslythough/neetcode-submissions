class DSU {
    vector<int> Parent, Size;
public:
    DSU(int n) : Parent(n + 1), Size(n + 1, 1) {
        for (int i = 0; i <= n; i++) Parent[i] = i;
    }

    int find(int node) {
        if (Parent[node] != node)
            Parent[node] = find(Parent[node]);
        return Parent[node];
    }

    bool unionSets(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (Size[pu] < Size[pv]) swap(pu, pv);
        Size[pu] += Size[pv];
        Parent[pv] = pu;
        return true;
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // earliest time when bottom-right and top-left becomes part of the same connected component
        int n =  grid.size();
        DSU dsu(n*n);
        vector<tuple<int, int, int>> positions;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                positions.emplace_back(grid[r][c], r, c);
            }
        }
        sort(positions.begin(), positions.end());
        vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        for(auto& [t,r,c] : positions){
            for(auto& [dr, dc] : dir){
                int nr = r + dr, nc = c + dc;
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]<=t) dsu.unionSets(r*n+c, nr*n + nc);
            }
            if(dsu.connected(0, n*n-1)) return t;
        }
        return n*n;
    }
};
