class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // The dependency graph will look like a DAG
        // You need to give an ordering
        // So its a TopoSort problem
        // You are only given list of edges, so create an adjacency list.
        // Use the ordering thing along with the cycle check through visited.
        if (numCourses<=0) return true;
        vector<vector<int>> adj(numCourses); // to store the out-neighbours
        for(const auto& vec : prerequisites) adj[vec[1]].push_back(vec[0]);
        // 0: unvisited, 1: actively visiting, 2: visited and verified to be free of cycles
        vector<int> state(numCourses, 0);
        // there could be disconnected graphs here, so search in all connected components
        for(int i = 0; i<numCourses; i++){
            if(state[i]==0){
                if(has_cycle(i,state,adj)) return false;
            }
        }
        return true;
        // here you have used a three-state backtracking method to avoid the binary backtracking explosive method
        // can distinguish between nodes in the path (recursion stack)
        // and the nodes that have been completely processed and verified to be safe
    }
private:
    bool has_cycle(int node, vector<int>& state, vector<vector<int>>& adj){
        if(state[node]==1) return true; // an in-path node is revisited , so its a cycle
        if(state[node]==2) return false; // previously processed node, skip traversal
        state[node] = 1;
        for(int prereq : adj[node]){
            if(has_cycle(prereq, state, adj)) return true;
        }
        state[node] = 2; // reset it for other paths, loops are not allowed but multiples parts ARE
        return false;
    }
};
