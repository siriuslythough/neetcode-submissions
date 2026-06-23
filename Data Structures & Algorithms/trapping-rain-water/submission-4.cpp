class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> postmax(height.size(), 0);
        vector<int> premax(height.size(), 0);
        premax[0] = height[0];
        postmax[height.size()-1] = height[height.size()-1];
        for(int i = 1; i<height.size(); i++){
            premax[i] = max(premax[i-1], height[i]);
        }
        for(int j = height.size()-2; j>=0; j--){
            postmax[j] = max(postmax[j+1], height[j]);
        }
        int total = 0;
        for(int k = 0; k<height.size(); k++){
            if(height[k]<premax[k] && height[k]<postmax[k]){
                total += min(premax[k], postmax[k]) - height[k];
            }
        }
        return total;
    }
};
