class UnionFind{
    vector<int> parent;
    vector<int> size;
public:
    UnionFind(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0; i<n+1; i++) parent[i] = i;
    }
    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    bool sizeunion(int u, int v){
        int ulp_u = find(u), ulp_v = find(v);
        if(ulp_u == ulp_v) return false; // that is the are not disjoint, already unionized.
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // LMAOOOO ACCOUNT MERGE IS LIKE THE ENTITY RESOLUTION!!!
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> email2acc; // email string to account index

        // Build the disjoint set
        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                const string& email = accounts[i][j];
                if(email2acc.count(email)){
                    uf.sizeunion(i, email2acc[email]);
                }else{
                    email2acc[email] = i;
                }
            }
        }
        map<int, vector<string>> emailgroup; // index to list of emails, and the contents (emails at an index stay sorted)
        // group emails by leader account
        for(const auto& [email, acc] : email2acc){
            int leader = uf.find(acc);
            emailgroup[leader].push_back(email);
        }

        // build result
        vector<vector<string>> res;
        for(auto& [acc, email] : emailgroup){
            sort(email.begin(), email.end());
            vector<string> merged;
            merged.push_back(accounts[acc][0]);
            merged.insert(merged.end(), email.begin(), email.end());
            res.push_back(merged);
        }

        return res;
    }
};
