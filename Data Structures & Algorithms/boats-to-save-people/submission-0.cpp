class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int l = 0;
        int r = n-1;
        int boats = 0;
        while(l<=r){
            if(people[l]+people[r]<=limit) l++;
            r--;
            boats++; // boats will be used in each parse, just that if sum of two is not in the limits, give the fatty their own boat.
        }
        return boats;
    }
};