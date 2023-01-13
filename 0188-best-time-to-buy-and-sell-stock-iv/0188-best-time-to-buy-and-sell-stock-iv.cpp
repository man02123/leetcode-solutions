class Solution {
public:int dp[1001][101][2];
    int maxProfit(int k, vector<int>& p) {
        memset(dp,-1,sizeof(dp));
        
        return solve(p,0,k,1);
    }
    int solve(vector<int>& p,int ind,int tlim,int canbuy)
    {
        if(ind>=p.size() || tlim<0)return 0;
        
        //if(ind==p.size()-1 && canbuy==0)return p[ind];
        if(dp[ind][tlim][canbuy]!=-1)return dp[ind][tlim][canbuy];
        
        int b=0,nb=0;
        if(canbuy==1)
        {
            b=max(-p[ind]+solve(p,ind+1,tlim-1,0),solve(p,ind+1,tlim,1));
            
        }
        else
            nb=max(solve(p,ind+1,tlim,1)+p[ind],solve(p,ind+1,tlim,0));
        
        return dp[ind][tlim][canbuy]=max(b,nb);
        
        
    }
};