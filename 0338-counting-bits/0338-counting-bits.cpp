class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
       // res.push_back(0);
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        
        for(int i = 0;i<=n ;i++){
            res.push_back(solve(i,dp));
        }
        return res;
    }
    int solve(int num , int dp[]){
        if(num==0)
            return 0;
        if(num == 1)
            return 1;
        if(dp[num] != -1)
            return dp[num];
        
        if(num%2 == 0)
            return dp[num] = solve(num/2,dp);
        else
            return dp[num] = 1+solve(num/2,dp);
    }
};