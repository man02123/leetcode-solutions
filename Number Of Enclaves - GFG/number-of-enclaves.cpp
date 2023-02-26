//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &g) {
        int res=0;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        
        int n=g.size();
        int m=g[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          if((i==0 || j==0 || i==n-1 || j==m-1) && g[i][j]==1)
          q.push({i,j});
          
          while(q.size()>0)
          {
              int x=q.front().first;
              int y=q.front().second;
              q.pop();
              visited[x][y]=1;
              
              for(int k=0;k<4;k++)
              {
                  int nx=x+dx[k];
                  int ny=y+dy[k];
                  if(nx>=0 && ny>=0 && nx<n && ny<m && (!visited[nx][ny]) && g[nx][ny]==1)
                  q.push({nx,ny});
              }
              
          }
          for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
            if(!visited[i][j] && g[i][j]==1)
             res++;
          
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends