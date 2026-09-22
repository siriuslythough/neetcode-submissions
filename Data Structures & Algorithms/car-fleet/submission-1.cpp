class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> xv;
        int n = position.size(); 
        for(int i = 0; i<n; i++){
            xv.push_back({position[i], speed[i]});
        }
        sort(xv.rbegin(), xv.rend()); //  soprt descending!
        int fleets = 1;
        double prevt = (double)(target-xv[0].first)/xv[0].second;
        for(int i = 1; i<n; i++){
            double currt = (double)(target-xv[i].first)/xv[i].second;
            if(prevt<currt){
                fleets++;
                prevt = currt;
            }
        }
        return fleets;
       
    }
};
