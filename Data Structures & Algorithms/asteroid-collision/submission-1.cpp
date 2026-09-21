class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int a : asteroids){
            while(!ans.empty() && ans.back()>0 && a<0 && ans.back()<-a) ans.pop_back();
            if(!ans.empty() & ans.back()>0 && a<0 && ans.back() == -a) ans.pop_back();
            else if(ans.empty() || ans.back()<0 || a>0) ans.push_back(a);
        }
        return ans;
    }
};