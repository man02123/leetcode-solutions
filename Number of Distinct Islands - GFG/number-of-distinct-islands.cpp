//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:set<vector<pair<int,int>>> st;
  int n,m;
    int countDistinctIslands(vector<vector<int>>& g) {
        n  = g.size();
        m = g[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(!vis[i][j]  && g[i][j] ==1)
                {
                    bfs(g,vis,i,j);
                }
            }
        }
        
        return st.size();
    }
    void bfs(vector<vector<int>>& g ,vector<vector<int>>& vis,int row,int col){
        
        queue<pair<int,int>> q;
        int i = row;
        int j = col;
        
        q.push({row,col});
        
        vector<pair<int,int>> fig;
        int dx[4]  ={1,0,-1,0};
        int dy [4] = {0,-1,0,1};
        
        while(q.size()>0)
        {
            int x = q.front().first;
            int y =  q.front().second;
            fig.push_back({x-i,y-j});
            q.pop();
            
            for(int i = 0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx>=0 && ny>=0 && nx<n && ny<m && vis[nx][ny]==0 && g[nx][ny]==1){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
        st.insert(fig);
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends