class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for(int i = 0; i<nums.size(); i++){
            if(!dq.empty() && dq.front()<=i-k) dq.pop_front(); // when the last element you stored is out of the window, pop it out
            while(!dq.empty() && nums[dq.back()]<= nums[i]) dq.pop_back(); // remove the elements that disrupt the decreasing order, clean it to add the next smaller element
            dq.push_back(i); // the next smaller element comes from the next entries 
            if(i>=k-1) res.push_back(nums[dq.front()]); // have populated the window and maintained k elements
        } 
        return res;
    }
};
