class Solution {
public:int asc;
    int minimumDeleteSum(string s1, string s2) {
        int dp[1002][1002];
        dp[0][0]=0;
        for(int i=1;i<=s1.size();i++)
        {
            dp[i][0]=dp[i-1][0]+(int)s1[i-1];
        }
         for(int j=1;j<=s2.size();j++)
        {
            dp[0][j]=dp[0][j-1]+(int)s2[j-1];
        }
        
        for(int i=1;i<=s1.size();i++)
            for(int j=1;j<=s2.size();j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=min(dp[i-1][j]+(int)s1[i-1],dp[i][j-1]+(int)s2[j-1]);
                }
            }
        
      // for(int i=0;i<=s1.size();i++)
      //       for(int j=0;j<=s2.size();j++)
        
        return dp[s1.size()][s2.size()];
    }
//     int lis(string s1, string s2,int ind1,int ind2)
//     {
//         if(ind1>=s1.size() || ind2>=s2.size())
//         {
//             return 0;
//         }
        
//         if(s1[ind1]==s2[ind2])
//         {
            
//             return 1+lis(s1,s2,ind1+1,ind2+1);
//         }
        
//         return min((int)s1[ind1]+lis(s1,s2,ind1+1,ind2),s2[ind2]+lis(s1,s2,ind1,ind2+1),);
        
        
//     }
};