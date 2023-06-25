class Solution {
public:int dp[101][201];
    int countRoutes(vector<int>& lo, int s, int f, int fuel) {
        memset(dp,-1,sizeof(dp));
        return solve(lo , s,f,fuel);
    }
    int solve(vector<int>& lo,int s,int f,int fuel){
        
        if(fuel==0  && s==f )
            return 1;
        
        if(fuel<=0)
          return 0;
        if(dp[s][fuel]!=-1)
            return dp[s][fuel];
        
        int ways=0;
        if(s==f)
        {
            ways=1;
            for(int i=0;i<lo.size();i++)
            {
                if(i!=s)
                {
                    int diff = abs(lo[s]-lo[i]);
                    if(fuel>=diff)
                    {
                      ways+=(solve(lo,i,f,fuel-diff))%1000000007;
                       ways=ways%1000000007; 
                    }
                }
            }
        }
        else
        {
            for(int i=0;i<lo.size();i++)
            {
                if(i!=s)
                {
                    int diff = abs(lo[s]-lo[i]);
                    if(fuel>=diff)
                    {
                      ways+=(solve(lo,i,f,fuel-diff))%1000000007;
                        ways=ways%1000000007;
                    }
                }
            }
            
        }
        return dp[s][fuel] = (ways)%1000000007;
        
    }
};