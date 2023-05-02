//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:vector<int> dx,dy;
  //typedef pair<int,int> pi;
    int shortestPath(vector<vector<int>> &g, pair<int, int> s,
                     pair<int, int> d) {
                         
                       dx = {-1,0,1,0};
                       dy = {0,1,0,-1};
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{s.first,s.second}});
        
    vector<vector<int>> vis(g.size(),vector<int>(g[0].size(),0));
    
        vis[s.first][s.second] =1;
        if(g[s.first][s.second]==0)
            return -1;
        if(g[d.first][d.second] ==0)
            return -1;
        
        while(!q.empty())
        {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int dist =q.front().first;
            if(x==d.first  && y==d.second)
                return dist;
            q.pop();
            
            for(int i =0 ;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx>=0 && nx<g.size() && ny>=0 && ny<g[0].size() && vis[nx][ny]==0 &&g[nx][ny]!=0)
                {
                    vis[nx][ny] = 1;
                    q.push({1+dist,{nx,ny}});
                }
                
            }
            
            
        }
        return -1;
        
    }
        // code here
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends