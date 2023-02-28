//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int n;
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        n=V;
       vector<int> visited(n,0);
        vector<int> pathvisited(n,0);
        
        for(int node=0;node<n;++node)
        {
            if(!visited[node] )
            if(dfs(adj,visited,pathvisited,node)==true)
                return true;
        }
        return false;
  
    }
    bool dfs(vector<int> adj[],vector<int> &visited,vector<int> &pathvisited,int node)
    {
        visited[node]=true;
        pathvisited[node]=1;
        
        for(auto tnode:adj[node])
        {
            if(!visited[tnode])
            {
                if(dfs(adj,visited,pathvisited,tnode)==true)
                return true;
            }
            else if(pathvisited[tnode])
            return true;
        }
        pathvisited[node]=0;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends