class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // do the toposort with bfs, use Kahn's algo
        // here cycle detection via dfs wont be enough cuase you need order,
        // and for order on DAG just do Kahn's 
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(const auto& vec : prerequisites) adj[vec[1]].push_back(vec[0]);
        vector<int> state(n, 0);
        for(int i = 0; i<n; i++){
            if(hascycle(i, state, adj)) return {};
        }
        vector<int> indeg(n, 0);
        queue<int> q;
        vector<int> order;
        for(int i = 0; i<n; i++){
            for(int nbd : adj[i]){
                indeg[nbd]++;
            }
        }
        for(int i = 0; i<n; i++){
            if(indeg[i]==0){
                q.push(i);
                order.push_back(i);
            }
        }
        //Kahn's algorithm
        while(!q.empty()){
            int src = q.front(); 
            q.pop();
            for(auto child : adj[src]){
                indeg[child]--;
                if(indeg[child]==0){
                    q.push(child);
                    order.push_back(child);
                }
            }
        }
        return order;
    }
private:
    bool hascycle(int node, vector<int>& state, vector<vector<int>>& adj){
        if(state[node]==1) return true;
        if(state[node]==2) return false;
        state[node]=1;
        for(int child : adj[node]){
            if(hascycle(child, state, adj)) return true;
        }
        state[node] = 2;
        return false;
    }
};
