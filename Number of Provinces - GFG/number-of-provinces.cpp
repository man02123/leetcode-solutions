//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int cnt;
    int numProvinces(vector<vector<int>> adj, int v) {
        cnt=0;
        vector<bool> visited(v,0);
        for(int i=0;i<v;i++)
        {
            if(visited[i]==0)
            {
                dfs(i,adj,visited);
                cnt++;
            }
        }
        return cnt;
    }
    void dfs(int ind,vector<vector<int>> &adj,vector<bool> &visited)
    {
        visited[ind]=true;
        for(int j=0;j<adj[ind].size();j++)
        {
            if(!visited[j] && adj[ind][j]==1)
            dfs(j,adj,visited);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends