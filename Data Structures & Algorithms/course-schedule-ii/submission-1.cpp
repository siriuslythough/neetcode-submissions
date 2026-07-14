class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Here we need to return valid orderings, so we go for the Topological Sort approach with BFS
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(int i = 0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]); // edge is from .[1] to .[0]
                                                                     // so we are storing out-neighbours in the adj list
        }
        // TOPOSORT:
        //          > insert all nodes into the stack with in-degree 0
        //          > Take them out of the queue and reduce the in-degree of the adjacent nodes
        vector<int> indegree(n, 0);
        for(int i = 0; i<n; i++){
            for(auto it : adj[i]){
                indegree[it]++; // it is the out-neighbour of the node i, done through entries in adj[i]
            }
        }
        queue<int> q;
        for(int i = 0; i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is not in topo, so remove it from graph and modifgy the indegree
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(topo.size() == n){ // no cyle was there
            return topo;
        }
        return {};
    }
};
