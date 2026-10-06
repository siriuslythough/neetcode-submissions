class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        for(auto dep : prerequisites) {adj[dep[1]].push_back(dep[0]); indegree[dep[0]]++;}
        for(int i = 0; i<numCourses; i++){if(indegree[i]==0) q.push(i);}
        vector<int> topo;
        while(!q.empty()){
            int p = q.front(); q.pop();
            topo.push_back(p);
            for(int c : adj[p]){
                indegree[c]--;
                if(indegree[c] == 0) q.push(c);
            }
        }
        if(topo.size()!=numCourses) return {};
        return topo;
    }
};
