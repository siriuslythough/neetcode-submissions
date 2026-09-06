class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // fixed window size, compare the left and right ends. if right end is not closer than the left end return the subarray, else move both the left and the right pointer.
        int l = 0;
        while(l+k<arr.size()){
            if(abs(arr[l]-x)>abs(arr[l+k]-x) || abs(arr[l]-x) == abs(arr[l+k]-x) && arr[l+k]==arr[l]) l++;
            else break;
        }
        vector<int> res;
        for(int i = l; i<l+k; i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};