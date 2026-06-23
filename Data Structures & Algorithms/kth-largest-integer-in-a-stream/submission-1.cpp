// why priority queue:
// insertion & removal time: O(logn)
// retrieval time: O(1)

class KthLargest {
private:
    int globalK;
    priority_queue<int, vector<int>, greater<int>> minheap;

public:
    KthLargest(int k, vector<int>& nums) {
        globalK = k;
        for(int i = 0; i<nums.size(); i++) add(nums[i]);
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>globalK) minheap.pop();
        return minheap.top();
    }
};
