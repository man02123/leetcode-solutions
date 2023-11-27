class Solution {
public:
    int dp[4][4][5002];
    int knightDialer(int n) {
    
      int ans = 0;
        memset(dp,-1,sizeof(dp));
        
      for(int i =0;i<4;i++){
          for(int j =0;j<3;j++){
                  ans  =(ans+ dfs(i,j,n)% ((int)1e9+7))% ((int)1e9+7);
          }
      }
        
        return ans;
    }
    int  dfs( int r ,int c,int n){
       int mod = 1e9+7;
        if(c<0 || r<0 || r>=4 || c>2 || (r==3 && c==0) || (r==3 && c==2)){
            return 0;
        }
        if(dp[r][c][n] != -1)return dp[r][c][n];
        
        
        if(n ==1)return 1;
        
        int ans = 0;
        
        ans = (ans+ dfs(r-2,c+1,n-1)% mod)%mod;
        ans =(ans+ dfs(r-2,c-1,n-1)% mod)%mod;
        ans = (ans +dfs(r-1,c+2,n-1)% mod)%mod;
        ans = (ans+ dfs(r+1,c+2,n-1)% mod)%mod;
        ans = (ans+ dfs(r+2,c-1,n-1)% mod)%mod;
        ans = (ans+ dfs(r+2,c+1,n-1)% mod)%mod;
        ans = (ans+ dfs(r-1,c-2,n-1)% mod)%mod;
        ans = (ans+dfs(r+1,c-2,n-1)% mod)%mod;
        
        return dp[r][c][n] = ans% mod;
        
    }
};