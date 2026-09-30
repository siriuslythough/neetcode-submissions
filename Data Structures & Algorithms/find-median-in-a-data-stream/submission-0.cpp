class MedianFinder {
    priority_queue<int> small; // maxheap for lower half
    priority_queue<int, vector<int>, greater<int>> large; // minheap for upper half
public:
    MedianFinder() {
    }
    
    void addNum(int x) {
        if(!large.empty() && x>large.top()) large.push(x);
        else small.push(x);
        if((int)large.size() - (int)small.size() > 1) {small.push(large.top()); large.pop();}
        if((int)small.size() - (int)large.size() > 1) {large.push(small.top()); small.pop();}
    }
    double findMedian() {
        if(large.size()>small.size()) return large.top();
        else if(large.size()<small.size()) return small.top();
        else return 0.5*((double)large.top() + (double)small.top());
    }
};
