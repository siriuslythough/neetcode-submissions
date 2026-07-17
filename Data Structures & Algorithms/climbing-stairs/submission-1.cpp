class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 0;
        else if(n==1) return 1;
        else if(n==2) return 2;
        else{
            vector<int> ans(n+1);
            int p2 = 1;
            int p1 = 2;
            int pi;
            for(int i = 3; i<=n; i++){
                pi = p1 + p2;
                p2 = p1;
                p1 = pi;
            }
            return p1;
        }
    }
};
