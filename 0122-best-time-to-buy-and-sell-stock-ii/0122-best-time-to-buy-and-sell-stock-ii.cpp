class Solution {
public:
    int maxProfit(vector<int>& p) {
        vector<vector<int>> dp(p.size()+1,vector<int>(2,-1));
        int x=helper(p,0,1,dp);
        
        
        return x;
    }
    int helper(vector<int>& p,int ind,bool buystate,vector<vector<int>> &dp)
    {
            if(ind==p.size()-1 && buystate==0)
                return p[ind];
            else if(ind==p.size()-1 && buystate==1)
                return 0;
        
            if(dp[ind][buystate]!=-1)return dp[ind][buystate];
            
            int pf1=0,pf2=0;
            if(buystate==true)
                pf1=max(-p[ind]+helper(p,ind+1,0,dp),helper(p,ind+1,1,dp)); //buy of not buy
            else
                pf2=max(p[ind]+helper(p,ind+1,1,dp),helper(p,ind+1,0,dp));
        
            return dp[ind][buystate]=max(pf1,pf2);
        
    }
};