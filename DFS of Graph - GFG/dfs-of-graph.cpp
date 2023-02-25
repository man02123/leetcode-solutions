//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:vector<int> res;
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<int> visited(V+1,0);
       
       for(int i=0;i<V;i++)
       {
           if(!visited[i])
           {
               dfs(i,adj,visited);
           }
       }
       return res;
       
    }
    void dfs(int ind,vector<int> adj[],vector<int> &visited)
    {
        visited[ind]=true;
        res.push_back(ind);
        
        for(int i=0;i<adj[ind].size();i++)
        {
            if(!visited[adj[ind][i]])
            {
                dfs(adj[ind][i],adj,visited);
            }
        }
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends