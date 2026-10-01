class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pickup_pq; // {from, id}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ongoing_pq; // {to, num_passengers}
        for(int i = 0; i<trips.size(); i++) pickup_pq.push({trips[i][1], i}); 
        int runcap = 0;
        int runpos = 0;
        while(!pickup_pq.empty()){
            auto ride = pickup_pq.top();
            pickup_pq.pop();
            int id = ride.second;
            int ridepos = trips[id][1]; // start position of this new ride
            while(!ongoing_pq.empty() && ongoing_pq.top().first<=ridepos) {runcap -= ongoing_pq.top().second; ongoing_pq.pop();}
            // THIS WAS NOT CORRECT BECAUSE YOU WERE NOTY TRACKING THE ACTUAL PEPOPLE GETTING OFF THE VEHICLE AS EACH TO LOCATIONH WAS REACHED if(runpos<=ridepos) runcap = max(0, runcap - capacity); // exit from a ride
            runcap += trips[id][0];
            if(runcap>capacity) return false;
            ongoing_pq.push({trips[id][2], trips[id][0]}); // end position of this ride if it would be completed before next one
        }
        return true;
    }
};