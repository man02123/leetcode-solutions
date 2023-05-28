class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        
      return solve(cuts,1,m,dp); 
    }
    
    int solve(vector<int>& cuts, int start,int end,vector<vector<int>> &dp)
    {
        if(start>end)
            return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
      
        int tans  = INT_MAX;
      
        
        for(int part = start;part<=end;part++)
        {
            int ans =  cuts[end+1]-cuts[start-1] +
                solve(cuts,start,part-1,dp)+solve(cuts,part+1,end,dp);
            tans = min(tans,ans);
        }
        return dp[start][end] =tans;
        
    }
};