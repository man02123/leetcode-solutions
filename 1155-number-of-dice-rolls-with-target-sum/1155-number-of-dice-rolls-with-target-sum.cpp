class Solution {
public:int size;
    int mod;
    int numRollsToTarget(int n, int k, int target) {
        mod=1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        
      int x= (memo(target,n,k,dp));
       return (dp[n][target])%mod;
    }
    int memo(int tgt,int dice,int k,vector<vector<int>> &dp)
    {
       if(tgt==0 && dice!=0)return 0;
        if(tgt!=0 && dice==0)return 0;
        if(tgt<0 || dice<0)return 0;
        
        
        if(tgt==0 && dice==0) return 1;
        //cout<<tgt<<dice<<endl;
        if(dp[dice][tgt]!=-1)return dp[dice][tgt];
        
         long long ans=0;
        for(int i=1;i<=k;i++)
        {
           ans+=(memo(tgt-i,dice-1,k,dp)%mod)%mod;
        }
        return dp[dice][tgt]=(ans)%mod;
      
     
      
    }
    
};