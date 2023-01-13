class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        vector<vector<int>> dp(p.size()+1,vector<int>(2,-1));
        return solve(p,fee,0,1,dp);
        
    }
    int solve(vector<int>& p,int fee,int ind,bool canbuy,vector<vector<int>> &dp)
    {
        if(ind>=p.size())return 0;
        if(dp[ind][canbuy]!=-1)return dp[ind][canbuy];
        
        int buy=0,sell=0;
        if(canbuy==true)
        {
            buy=max(-p[ind]+solve(p,fee,ind+1,0,dp),solve(p,fee,ind+1,1,dp));
        }
        else
        {
            sell=max(p[ind]-fee+solve(p,fee,ind+1,1,dp),solve(p,fee,ind+1,0,dp));
        }
        return dp[ind][canbuy]=max(buy,sell);
        
        
        
        
    }
};