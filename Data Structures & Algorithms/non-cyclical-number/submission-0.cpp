class Solution {
public:
    bool isHappy(int n) {
        if(n<=0) return false;
        unordered_set<int> seen;
        return digitsum(n, seen);
    }
private:
    bool digitsum(int n, unordered_set<int>& seen){
        int digi2sum = 0;
        int sq;
        while(n>0){
            sq = n%10;
            digi2sum += sq*sq;
            n/=10;
        }
        if(digi2sum != 1 && seen.find(digi2sum)!=seen.end()) return false;
        else{
            if(digi2sum == 1) return true;
            else{
                seen.insert(digi2sum);
                return digitsum(digi2sum, seen);
            }
        }
    }
};
