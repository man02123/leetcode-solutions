//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& e,
                 int dist) {
                     vector<vector<int>> g(n,vector<int>(n,1e9));
        
        for(auto it:e)
        {
            g[it[0]][it[1]] = it[2];
            g[it[1]][it[0]] = it[2];
        }
        for(int i=0;i<n;i++)
            g[i][i] =0;
        
        for(int k = 0; k<n ;k++)
        {
            for(int i= 0;i<n;i++)
            {
                for(int j= 0;j<n;j++)
                {
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
        int temp=n,res=0;
        
        for(int i = 0;i<n;i++)
        {
            int cnt = 0;
            for(int j =0;j<n;j++)
            {
                if(g[i][j]<=dist)
                    cnt++;
            }
            if(temp>=cnt)
            {
            temp = cnt;
                res=i;
            }
            
        }
       // int x = *min_element(res.begin(),res.end());
        
        return res;
                     
                     
                
                 }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends