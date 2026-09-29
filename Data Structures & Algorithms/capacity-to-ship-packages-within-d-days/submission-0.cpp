class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;
        for(int i = 0; i<weights.size(); i++){r+=weights[i]; l = max(l, weights[i]);}
        int mincap = r;
        while(l<=r){
            int m = l + (r-l)/2;
            int running_days = 0;
            int j = 0;
            while(j<weights.size()){
                int wt = 0;
                while(j<weights.size() && wt + weights[j]<=m){
                    wt+=weights[j];
                    j++;
                }
                running_days++;
            }
            if(running_days<=days) {r = m-1; mincap = m;}
            else l = m+1;
        }
        return mincap;
    }
};