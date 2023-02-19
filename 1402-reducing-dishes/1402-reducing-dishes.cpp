class Solution {
public:int dp[501][501];
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        memset(dp,-1,sizeof(dp));
        
        return solve(s,0,0);
        
    }
    int solve(vector<int>& s,int ind,int trem)
    {
        if(ind>=s.size())
            return 0;
        if(dp[ind][trem]!=-1)
            return dp[ind][trem];
        
        if(s[ind]<0)
        {
            int rem=solve(s,ind+1,trem+1);
            int nrem=(ind-trem+1)*s[ind]+solve(s,ind+1,trem);
            return dp[ind][trem]=max(rem,nrem);
        }
        else
            return dp[ind][trem]=(ind-trem+1)*s[ind]+solve(s,ind+1,trem);
           
    }
};