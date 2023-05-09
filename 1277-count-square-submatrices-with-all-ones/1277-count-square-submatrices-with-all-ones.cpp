class Solution {
public:
    int countSquares(vector<vector<int>>& ma) {
        vector<vector<int>> dp(ma.size(),vector<int> (ma[0].size(),0));
        int m = ma.size();
        int n = ma[0].size();
        int sum =0;
        
        for(int i = 0;i<m;i++)
        {
            dp[i][0] = ma[i][0];
            //sum+=ma[i][0];
        }
        for(int j = 0;j<n;j++)
        {
            dp[0][j] = ma[0][j];
            //sum+=ma[0][j];
        }
        
        
        for(int i = 1;i<m;i++)
        {
            for(int j = 1;j<n;j++)
            {
                
               if(ma[i][j] == 1)
                    dp[i][j] =1+ min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
        
        for(auto it:dp)
        {
            for(auto it2:it)
                sum+=it2;
                
        }
        return sum;
        
        
    }
};