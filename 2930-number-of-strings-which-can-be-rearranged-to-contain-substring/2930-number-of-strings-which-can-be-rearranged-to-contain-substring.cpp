class Solution {
public:
    int x;
    int mod = 1e9+7;
    int dp[100001][3][3][3];
    int stringCount(int n) {
     
        memset(dp,-1,sizeof(dp));
        
        if(n <4)return 0;
        if(n == 4) return 12;
        x = n;
        return solve(0,0,0,0);
        
    }
    int solve(int n , int l,int e,int t){
        
        if(x < n)return 0;
        
        if(x == n){
            if(l && (e>=2) && t)return 1;
            return 0;
        }
        if(dp[n][min(1,l)][min(2,e)][min(1,t)] != -1)return dp[n][min(1,l)][min(2,e)][min(1,t)];
        long long ans = 0;
        for(int i =0;i<26;i++){
            if((i+'a') == 'l')
                ans += (solve(n+1,l+1,e,t))%mod;
            else if((i+'a') == 'e')
                ans =(ans+ (solve(n+1,l,e+1,t))%mod)%mod;
                else if((i+'a') == 't')
                ans =(ans+ (solve(n+1,l,e,t+1))%mod)%mod;
               else
                   ans= (ans+ (solve(n+1,l,e,t))%mod)%mod;
            }
          
    return dp[n][min(1,l)][min(2,e)][min(1,t)]=(ans)%mod;
 }   
};