class Solution {
public:
    int dp[60][2];
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        
        return solve(n,n,0);
        
    }
    int solve(int n,int sum,bool broken){
        if(sum < 0 || n<0)
            return 0;
        
        if(dp[n][broken] != -1)return dp[n][broken];
        
        int ans = 1;
        
        if(broken){
            for(int i = 1;i<=n;i++){
            int x = i*solve(n-i,sum-i,broken);
            ans = max(ans,x);
        }
        }
            
            else{
                for(int i = 1;i<n;i++){
            int x = i*solve(n-i,sum-i,!broken);
            ans = max(ans,x);
                
        }
            
        }
        
       return dp[n][broken] = ans; 
    }
};