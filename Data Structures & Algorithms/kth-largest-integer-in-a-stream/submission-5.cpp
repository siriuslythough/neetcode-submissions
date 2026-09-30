class KthLargest {
    // kth element is the .top() of a k-size min-heap
private:
    int globalK;
    priority_queue<int, vector<int>, greater<int>> minh;
public:
    
    KthLargest(int k, vector<int>& nums) {
        globalK = k;
        for(int i : nums) add(i);

    }
    
    int add(int val) {
        // clearly mentioned in teh question that first add then give the kth largest
        minh.push(val);
        if(minh.size()>globalK)minh.pop(); // maintain size k + if new one is the k+1th, it is popped out
        return minh.top();
    }
};
