class Solution {
public:
    int maxProfit(vector<int>& p) {
        vector<vector<vector<int>>> dp(p.size(), vector<vector<int>>(2, vector<int>(3, -1))) ;
        return solve(p,0,2,1,dp);
    }
    
    int solve(vector<int> &p,int ind,int tlim,bool canbuy, vector<vector<vector<int>>> &dp)
    {
        if(ind>=p.size() || tlim<0)return 0;
        
        if(ind==p.size()-1 && canbuy==false)return p[ind];
       
        if(dp[ind][canbuy][tlim]!=-1) return dp[ind][canbuy][tlim];
        
        int b=0,s=0;
        if(canbuy==true)
        {
            b=max(-p[ind]+solve(p,ind+1,tlim-1,0,dp),solve(p,ind+1,tlim,1,dp)); 
        }
        else
            s=max(p[ind]+solve(p,ind+1,tlim,1,dp),solve(p,ind+1,tlim,0,dp));
        
        return dp[ind][canbuy][tlim]=max(b,s);
        
    }
    
    
};