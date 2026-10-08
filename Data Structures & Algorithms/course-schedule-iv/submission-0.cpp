class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // use set can you dont need just one ordering now, you need to have a set of ALL the predecessors for each node
        vector<unordered_set<int>> adj(numCourses), isPrereq(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        for(auto& dep : prerequisites){indegree[dep[1]]++; adj[dep[0]].insert(dep[1]);}
        for(int i = 0; i<numCourses; i++){if(indegree[i]==0) q.push(i);}
        while(!q.empty()){
            int p = q.front(); q.pop();
            for(int c : adj[p]){
                isPrereq[c].insert(p); // add current
                isPrereq[c].insert(isPrereq[p].begin(), isPrereq[p].end()); // add all the other prereqs too
                indegree[c]--;
                if(indegree[c]==0) q.push(c);
            }
        }
        vector<bool> res;
        for(auto& q : queries){
            res.push_back(isPrereq[q[1]].count(q[0]));
        }
        return res;
    }
};