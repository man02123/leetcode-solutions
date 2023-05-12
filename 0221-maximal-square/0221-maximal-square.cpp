class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        vector<vector<int>> dp(m.size(),vector<int>(m[0].size()));
        int maxi= 0;
        for(int i=0;i<m.size();i++)
        {
            for(int j = 0;j<m[0].size();j++)
            {
                dp[i][j] = m[i][j] -'0';
                maxi = max(maxi,dp[i][j]);
            }
        }
        
         for(int i=1;i<m.size();i++)
        {
            for(int j = 1;j<m[0].size();j++)
            {
                if(dp[i][j]  ==1)
                {
                    dp[i][j]  = 1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                    maxi = max(maxi,dp[i][j]);
                }
            }
         }
        return maxi*maxi;
        
    }
};