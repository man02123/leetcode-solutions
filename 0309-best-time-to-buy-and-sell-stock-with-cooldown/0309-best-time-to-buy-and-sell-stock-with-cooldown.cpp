class Solution {
public:int dp[5001][2][2];
    int maxProfit(vector<int>& p) {
        memset(dp,-1,sizeof(dp));
    return pft(p,0,1,0); 
        
    }
    int pft(vector<int>& p,int ind,bool canbuy,int cool)
    {
        
       if(ind>=p.size())return 0;
        int b=0,s=0,c=0;
        
        if(dp[ind][canbuy][cool]!=-1)return dp[ind][canbuy][cool];
        
        if(canbuy==true && cool==0)
        {
            b=max(-p[ind]+pft(p,ind+1,!canbuy,0),pft(p,ind+1,canbuy,0));
            
        }
        else if(canbuy==false && cool!=1)
        {
            s=max(p[ind]+pft(p,ind+1,!canbuy,1),pft(p,ind+1,canbuy,0));
        }
        else if(cool==1)
            c=pft(p,ind+1,true,0);
        
        return dp[ind][canbuy][cool]=max(c,max(b,s));
        
        
    }
};