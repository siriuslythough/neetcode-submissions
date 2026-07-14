class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // You simply need to check if the dependency in prerequisites is having any CYCLE or not
        // So its a TOPOLOGICAL SORT to detect if the dependency graph is a DAG or not
        // Use DFS to detect a cycle OR BFS to do ao TopoSort
        // In this part it only asks if it is possible or not, so we do a DFS to detect cycles, 
        // When it asks for orderings also, we will do BFS TopoSort
        int n = numCourses;
        vector<bool> vis(n, false);
        vector<bool> inpath(n, false);
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i<prerequisites.size(); i++){ // [a,b] as prereq means a->b, to do a, first do b,
                                                     // so a has b as an out-neighbour our adjacency list has out-neighbours
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int c = 0; c<numCourses; c++){
            if(!vis[c]){
                if(!dfs(c, vis, inpath, adj)) return false;
            }
        }
        return true;
    }

private:
    bool dfs(int node, vector<bool>& vis, vector<bool>& inpath, vector<vector<int>>& adj){
        if(inpath[node]) return false; // At a node currently in out path, then we have a cycle
        if(vis[node]) return true; // At a node which was previously seen and now seeing through a different path
        vis[node] = true;
        inpath[node] = true;
        for(auto prereq : adj[node]){
            if(!dfs(prereq, vis, inpath, adj)) return false;
        }
        inpath[node] = false; // remove the explored path nodes from the inpath, so it can be explored from other paths
        return true;
    }
};
