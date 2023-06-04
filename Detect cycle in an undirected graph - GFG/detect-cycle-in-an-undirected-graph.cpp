//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
       
       vector<int> vis(v,0);
       bool ans  = false;
       for(int i  = 0;i<v;i++)
       {
           if(!vis[i])
           ans = ans | dfs(adj,i,vis,-1);
       }
       return ans;
    }
    bool dfs(vector<int> adj[] , int node, vector<int> &vis ,int parent)
    {
        bool ans = false;
        vis[node]  =1;
        for(auto it:adj[node])
        {
            int child = it;
            if(vis[child]==1 && child!=parent)
            {
                return true;
            }
            else if(vis[child]==0)
            {
                ans|=dfs(adj,child,vis,node);
            }
        }
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