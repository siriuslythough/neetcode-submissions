class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        int m;
        //For convergence problems like finding a minimum inflection point, 
        //change the condition to while (l < r). 
        //The loop stops the exact millisecond l and r MEET AT THE MINIMUM.
        while(l<r){
            m = l + (r-l)/2;
            if(nums[r]<nums[m]){//you check with the right part because
                                //in a sorted array, arr[right]>arr[middle]
                                //can't really hold that condition up on left though
                                //because for arr[left]<arr[middle], you can have
                                //arr[l]==arr[m] also, and no check can prevent that, but when its
                                //arr[r]==arr[m], then we know its the end and we can keep r at m only
                l=m+1;
            }
            else{
                r=m;
            }
        }
        return nums[l]; //l will surely jump pas the min thats 
                        //in the unsorted part, so that l=m+1 would be the min
    }
};
