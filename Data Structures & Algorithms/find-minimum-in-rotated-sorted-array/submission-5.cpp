class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        vector<int> v = piles;
        sort(v.begin(), v.end());
        int max_pile = v[v.size()-1];
        int i = max_pile;
        long long run_sum = 0;
        for(int l = 0; l<v.size(); l++){
            run_sum+=(v[l]+i-1)/i; 
        }
        int rate = i;
        for(int b = max_pile/2; b>=1; b/=2){
            while(i-b>0 && run_sum<=h){
                i = i-b;
                run_sum = 0;
                for(int idx = 0; idx<v.size(); idx++){
                    run_sum+=(v[idx]+i-1)/i;
                }
                

                if (run_sum <= h) { //If this newly decremented speed still finishes within h hours, 
                // update our tracking rate to capture this lower speed!
                    rate = min(rate, i); 
                }
            }
            if (run_sum > h) {
                i = i + b;
                run_sum = 0;
                for(int idx = 0; idx < v.size(); idx++){
                    run_sum += (v[idx] + i - 1) / i;
                }
                if (run_sum <= h) {
                    rate = min(rate, i); //When we step back up to a working speed, we must record 
                // this valid rate to prevent TLE and lock in our progression.
                }
            }
        }
        return rate;
    }
};
