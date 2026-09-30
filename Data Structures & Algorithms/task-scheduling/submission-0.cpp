class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // execute the most frequent one, and in that gap execute the other tasks
        vector<int> count(26,0);
        for(char task : tasks) count[task-'A']++;
        priority_queue<int> pq;
        for(int cnt : count){
            if(cnt>0){
                pq.push(cnt);
            }
        }
        int time = 0;
        queue<pair<int, int>> q;
        while(!pq.empty() || !q.empty()){
            time++;
            if(pq.empty()) time = q.front().second;
            else{
                int cnt = pq.top()-1; // execute the task with the maximum frequency
                pq.pop();
                if(cnt>0) q.push({cnt, time + n});
            }
            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
