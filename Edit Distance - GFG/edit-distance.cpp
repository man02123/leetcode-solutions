//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
        
        for(int i=0;i<=t.size();i++)
        dp[0][i]=i;
        for(int i=0;i<=s.size();i++)
        dp[i][0]=i;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=1;j<=t.size();j++)
            {
                if(s[i-1]==t[j-1])
                dp[i][j] = dp[i-1][j-1];
                else
                {
                    int ins= 1+dp[i][j-1];
                    int del=1+dp[i-1][j];
                    int rep = 1+dp[i-1][j-1];
                    dp[i][j] = min({ins,del,rep});
                }
            }
        }
        return dp[s.size()][t.size()];
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends