//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> g[]) {
        
         vector<int> vis(V,0);
       //v[0]=true;
        bool res=false;
       for(int i=0;i<V;i++)
       {
           if(vis[i]==0)
           res=res || dfs(i,-1,g,vis);
       }
       return res;
        
        
    }
    
    
    bool dfs(int node, int par, vector<int> g[], vector<int> &vis)
{
 
  vis[node] = 1;

  int ans = false;
  for (auto it : g[node])
  {
    if (vis[it] == 0 )
      ans = ans || dfs(it, node, g, vis);
    else if (it != par)
      ans = true;
  }
  //cout << "man";
  return ans;

}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends