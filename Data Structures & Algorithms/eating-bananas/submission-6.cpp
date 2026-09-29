class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // O(nlogM) approach
        int l = 1;
        int r = 0;
        for(int i = 0; i<piles.size(); i++){
            r = max(r, piles[i]);
        } 
        int ans = r;
        while(l<=r){
            int m = l + (r-l)/2;
            int hours = 0;
            for(int i = 0; i<piles.size(); i++) hours += (piles[i]+m-1)/m;
            if(hours<=h) {ans = m; r = m-1;} // try for a slower valid speed
            else l = m+1; // try for a larger valid speed
        }
        return ans;
    }
};
