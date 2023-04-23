class Solution {
public:int dp[100001][3][2];
    int maxProfit(vector<int>& p) {
       // vector<vector<vector<int>>> dp(p.size(), vector<vector<int>>(2, vector<int>(3, -1))) 
        memset(dp,-1,sizeof(dp));
        return recur(p,0,2,1);
    }
    
    int recur(vector<int> &p,int ind,int k,bool canbuy)
    {
         
    if(k==0 && canbuy==true)
    return 0;
    
    if(ind>=p.size())
    return 0;
    
    
    if(dp[ind][k][canbuy]!=-1)
    return dp[ind][k][canbuy];
    
    if(canbuy==true  && k>0)
    {
        int by=-p[ind]+recur(p,ind+1,k-1,false);
        int nby=recur(p,ind+1,k,true);
        return dp[ind][k][canbuy]=max(by,nby);
    }
    
        int sl=p[ind]+recur(p,ind+1,k,true);
        int ns=recur(p,ind+1,k,false);
        return dp[ind][k][canbuy]=max(sl,ns);
    
        
    }
    
    
};