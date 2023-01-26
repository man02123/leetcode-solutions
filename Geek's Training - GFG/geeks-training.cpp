//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& g, int n) {
        
        int dp[n+1][3];
        memset(dp,0,sizeof(dp));
        dp[0][0]=g[0][0];
        dp[0][1]=g[0][1];
        dp[0][2]=g[0][2];
        // dp[0][0]=max(g[0][1],g[0][2]);
        // dp[0][1]=max(g[0][0],g[0][2]);
        // dp[0][2]=max(g[0][1],g[0][0]);
        
       for(int i=1;i<g.size();i++)
        for(int j=0;j<g[0].size();j++)
        {
           int  mx=0;
            for(int k=0;k<3;k++)
            {
                if(k!=j)
                mx=max(mx,dp[i-1][k]);
            }
              dp[i][j]=g[i][j]+mx;
        }
    int res=0;
    for(int i=0;i<3;i++)
    res=max(res,dp[n-1][i]);
    return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends