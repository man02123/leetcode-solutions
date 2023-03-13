//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& e, int n,int m, int src){
        vector<vector<int>> graph(n);
        for(int i=0;i<e.size();i++)
        {
                graph[e[i][0]].push_back(e[i][1]);
                graph[e[i][1]].push_back(e[i][0]);
        }
        
        queue<int> q;
        vector<int> dist(n,INT_MAX-5);
        dist[src]=0;
        q.push(src);
        
        while(q.size()>0)
        {
            int node=q.front();
            q.pop();
           
            for(auto it:graph[node])
            {
                if(dist[node]+1<dist[it])
                    {
                        q.push(it);
                        dist[it]=1+dist[node];
                    }
            }
        }
        for(int i=0;i<dist.size();i++)
        {
            if(dist[i]==INT_MAX-5)
            dist[i]=-1;
        }
        
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends