class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // TopoSort because we have a dependency graph, as a DAG, and we want to say if there can be an order that does not have any circular dependencies
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        for(int i = 0; i<prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int c = q.front(); q.pop();
            topo.push_back(c);
            for(int v : adj[c]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        return (topo.size() == numCourses)?true:false;
    }
};
