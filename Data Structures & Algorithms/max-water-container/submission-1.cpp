class Solution {
public:
    int maxArea(vector<int>& heights) {
        // brute force is O(n2), fix one, parse across, track the max you see
        // two pointers, from either, using the fact that max water depends on the min of the bars you have.
        int n = heights.size();
        int l = 0, r = n-1;
        int most = 0;
        int temp = 0;
        while(l<r){
            temp = (r-l)*min(heights[l], heights[r]);
            most = max(most, temp);
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return most;
    }
};
