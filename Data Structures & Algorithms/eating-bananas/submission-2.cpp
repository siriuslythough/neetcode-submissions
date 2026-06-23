class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int r = m*n-1;
        int k;
        int val;
        while(l<=r){
            k = (l+r)/2;
            val = matrix[k/n][k%n];
            if(val==target) return true;
            else if(val>target) r=k-1;
            else l = k+1;
        }
        return false;
    }
};
