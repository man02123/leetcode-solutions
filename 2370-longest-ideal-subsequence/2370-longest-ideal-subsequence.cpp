class Solution {
public:
    int longestIdealString(string s, int k) {
        int lis[150]={};
        
        int res=0;
        for(auto& i:s)
        {
            for(int j=i-k;j<=i+k;j++)
                lis[i]=max(lis[i],lis[j]);
                
            res=max(res,++lis[i]);
        }
        return res;
        
    }
};

   // int longestIdealString(string s, int k) {
   //      int dp[150] = {}, res = 0;
   //      for (auto& i : s) {
   //          for (int j = i - k; j <= i + k; ++j)
   //              dp[i] = max(dp[i], dp[j]);
   //          res = max(res, ++dp[i]);
   //      }
   //      return res;
   //  }