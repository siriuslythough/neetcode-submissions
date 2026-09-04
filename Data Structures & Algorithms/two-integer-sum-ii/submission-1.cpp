class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // since this is sorted you can use the stupid incomplete logic you used earlier that failed at [3,2,3]
        int n = numbers.size();
        int i = 0, j = n-1;
        while(i<j){
            if(numbers[i]+numbers[j]<target) i++;
            else if (numbers[i]+numbers[j]>target) j--;
            else return {i+1,j+1};
        }
    }
};
