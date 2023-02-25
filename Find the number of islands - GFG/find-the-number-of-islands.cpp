//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int numIslands(vector<vector<char>>& g) {
       int n=g.size();
       int  m=g[0].size();
        int res=0;
       
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(g[i][j]=='1' && visited[i][j]==false)
                 bfs(i,j,visited,g),res++;
            }
        }
        return res;
    }
    
    
    void bfs(int i,int j,vector<vector<int>> &visited,vector<vector<char>> &g)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        
        
        while(q.size()>0)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int row=-1;row<=1;row++)
            {
                for(int col=-1;col<=1;col++)
                {
                    int dx=row+x;
                    int dy=col+y;
                    
                    if(dx>=0 && dy>=0 && dx<g.size() && dy<g[0].size() && g[dx][dy]=='1'&& visited[dx][dy]==false)
                    {
                        q.push({dx,dy});
                        visited[dx][dy]=true;
                    }
                }
            }
        }
        
    }
   
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends