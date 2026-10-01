class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // A CLASSIC "CHECK THE CONSTRAINTS" QUESTIONS: the location is bounded, and small enough. So you can maintain a running number of passengers for each to and from location
        // simple solution, just maintain the stamps of the change in number of passengers along the NUMBER LINE (what they call SWEEP LINE)
        vector<int> stops(1001, 0);
        for(const auto& trip : trips){
            stops[trip[1]] += trip[0];
            stops[trip[2]] -= trip[0];
        }
        int runcap = 0;
        for(int p : stops){
            runcap+=p;
            if(runcap>capacity) return false;
        }
        return true;
    }
};