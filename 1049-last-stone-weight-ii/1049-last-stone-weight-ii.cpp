class Solution {
public:
    int lastStoneWeightII(vector<int>& s) {
        int sum=0;
        int res=INT_MAX;
        sum=accumulate(s.begin(),s.end(),0);
        
        vector<vector<int>> dp(s.size()+1,vector<int>(sum+1,0));
        
        for(int i=0;i<dp.size();i++)
            dp[i][0]=1;
        
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=1;j<sum;j++)
            {
                if(j-s[i-1]>=0)
                {
                    dp[i][j]=dp[i-1][j-s[i-1]] || dp[i-1][j];
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        for(int i=sum/2;i>=0;i--)
            if(dp[s.size()][i]==true)
            res=min(sum-i-i,res);
        
        
        return res;
    }
};