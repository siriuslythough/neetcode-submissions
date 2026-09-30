class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // minheap1 <<proc, enque>, id> for cpu retrieval
        // minheap2 <<enque, proc>, id> to push elements into minheap1 as time>enque
        using task = pair<int, pair<int, int>>; // {enque_time, {proc_time, id}}
        priority_queue<task, vector<task>, greater<task>> qt;
        for(int i = 0; i<tasks.size(); i++)qt.push({tasks[i][0], {tasks[i][1], i}}); // push all tasks into time_heap by enque time
        using cputask = pair<int, int>; // {processing_time, original_time}
        priority_queue<cputask, vector<cputask>, greater<cputask>> cpu;
        vector<int> order;
        long long t = 0;
        while(!qt.empty() || !cpu.empty()){
            if(cpu.empty() && t<qt.top().first) t = qt.top().first;
            while(!qt.empty() && t>=qt.top().first){cpu.push({qt.top().second.first, qt.top().second.second}); qt.pop();} // push eligible tasks by start time to cpu heap
            if(!cpu.empty()){order.push_back(cpu.top().second); t+=cpu.top().first; cpu.pop(); }
        }
        return order;
    }
};