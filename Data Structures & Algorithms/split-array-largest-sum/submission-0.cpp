class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 0;
        for(int i : nums){l = max(l,i); r += i;}
        int minsum = r;
        while(l<=r){
            int m = l + (r-l)/2;
            int count = 1;
            int curr_sum = 0;
            for(int i : nums){
                if(curr_sum + i>m){count++; curr_sum = i;} // running sum that has overflown the max cap hence need to increment count 
                else curr_sum += i; // carry the running sum in the same m capacity
            }
            if(count<=k){minsum = m; r = m-1;}
            else l = m+1;
        }
        return minsum;
    }
};