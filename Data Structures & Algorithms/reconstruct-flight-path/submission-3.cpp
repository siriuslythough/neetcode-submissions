class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> adj;
        for(auto& ticket : tickets) adj[ticket[0]].push_back(ticket[1]);
        for(auto& [src, dest] : adj) sort(dest.rbegin(), dest.rend());
        vector<string> res;
        dfs("JFK", adj, res);
        reverse(res.begin(), res.end());
        return res;

    }
private:
    void dfs(const string& airport, unordered_map<string, deque<string>>& adj, vector<string>& res){
        while(!adj[airport].empty()){
            string dest = adj[airport].back();
            adj[airport].pop_back();
            dfs(dest, adj, res);
        }
        res.push_back(airport);
    }
};
