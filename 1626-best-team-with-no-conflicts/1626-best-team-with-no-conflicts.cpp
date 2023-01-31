class Solution {
public:
    int dp[1001][1001];
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        vector<pair<int,int>> t;
         memset(dp,-1,sizeof(dp));
        for(int i=0;i<s.size();i++)
            t.push_back({s[i],a[i]});
        
        sort(t.begin(),t.end());
        

        return solve(t,0,0);
     
    }
    int solve(vector<pair<int,int>> &t,int ind,int maxage)
    {
        if(ind>=t.size())
            return 0;
        if(dp[ind][maxage]!=-1)
            return dp[ind][maxage];
        
        if(maxage<=t[ind].second)
        {
            return dp[ind][maxage]=max(solve(t,ind+1,maxage),t[ind].first+solve(t,ind+1,t[ind].second));
        }
       
            return dp[ind][maxage]=solve(t,ind+1,maxage);
        
        
        
    }
};