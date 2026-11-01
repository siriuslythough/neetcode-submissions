class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea = 0;
        // area bw [l,r] = (r-l)*min(h[l],h[r])
        int l = 0, r=heights.size()-1;
        while(l<r){
            maxarea = max(maxarea, (r-l)*min(heights[l], heights[r]));
            if(heights[l]>heights[r]) r--;
            else l++;
        }
        return maxarea;
    }
};
