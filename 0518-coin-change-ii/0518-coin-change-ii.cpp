class Solution {
public:int dp[301][50002];
    int change(int amount, vector<int>& coins) {
       memset(dp,-1,sizeof(dp));
        
        for(int j=0;j<amount+1;j++)
            dp[0][j]=0;
        for(int j=0;j<coins.size()+1;j++)
            dp[j][0]=1;
        
        for(int i=1;i<coins.size()+1;i++)
            for(int j=1;j<amount+1;j++)
            {
                if(j>=coins[i-1])
                    dp[i][j]=(dp[i][j-coins[i-1]])+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        return dp[coins.size()][amount];
    }    
    
};