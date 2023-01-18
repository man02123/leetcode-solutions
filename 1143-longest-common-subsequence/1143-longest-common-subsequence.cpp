class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        vector<vector<int>>dp(t1.size(),vector<int>(t2.size(),-1));
       return solve(t1,t2,0,0,dp); 
    }
    int solve(string &t1,string &t2,int ind1,int ind2,vector<vector<int>> &dp)
    {
        if(ind1>=t1.size() || ind2>=t2.size())
            return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        
        if(t1[ind1]==t2[ind2])
            return dp[ind1][ind2]=1+solve(t1,t2,ind1+1,ind2+1,dp);
        else
        {
            return dp[ind1][ind2]=max(solve(t1,t2,ind1,ind2+1,dp),solve(t1,t2,ind1+1,ind2,dp));
        }
        
    }
};