class Solution {
public:
    int climbStairs(int n) {
        int p = 0;
        int np = 1;
        int ans = 0;
        for(int i =2;i<=n+1;i++){
          ans = p+np;
           p = np;
            np = ans;
          
        }
        return ans;
    }
};