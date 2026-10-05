class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // find the node with zero outdegree
        // [ai, bi] means edge ai -> bi
        vector<int> outdegree(n, 0);
        vector<int> indegree(n, 0);
        for(int i = 0; i<trust.size(); i++){
            outdegree[trust[i][0]-1]++;
            indegree[trust[i][1]-1]++;
        }
        for(int i = 0; i<n; i++){
            if((outdegree[i] == 0) && (indegree[i] == n-1)) return i+1;
        }
        return -1;
    }
};