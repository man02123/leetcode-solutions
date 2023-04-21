//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = 1000000007; 
    int totalWays(int n, int m, vector<vector<int>>& g) {
        
        bool flag1= false;
        bool flag2 = false;
        int flag3 = false;
        
        
        if(g[0][0]==1)
        return 0;
        
        
        for(int j=1;j<g[0].size();j++)
        {
            if(g[0][j]==1)
            flag1 = true;
            
            if(flag1 == true)
            g[0][j]=0;
            else
            g[0][j]=1;
        }
        g[0][0]=1;
         for(int i=1;i<g.size();i++)
        {
            if(g[i][0]==1)
            flag2 = true;
            
            if(flag2 == true)
            g[i][0]=0;
            else
            g[i][0]=1;
        }
        
        if(m==1 && n==1)
        return 1;
        
        if(g[n-1][m-1]==1)
        return 0;
        
        for(int i=1;i<g.size();i++)
        {
            for(int j=1;j<g[0].size();j++)
            {
                if(g[i][j]==0)
                g[i][j] = (g[i-1][j]+g[i][j-1])%mod;
                else g[i][j]=0;
            }
        }
        return (g[n-1][m-1])%mod;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends