//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int M, vector<vector<int>>& ed){
        vector<pair<int,int>> g[n];
        for(auto it:ed){
            g[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,INT_MAX);
        
        dist[0] = 0;
        
        queue<pair<int,int>> q;
        
        q.push({0,0});
        
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            
            for(auto it:g[node]){
                
                int adjnode = it.first;
                int di = it.second;
                if(dist[adjnode]> d+di)
                {
                    dist[adjnode] = d+di;
                }
                q.push({adjnode,d+di});
            }
            
        }
        vector<int> res;
        for(auto it:dist){
            if(it == INT_MAX)
            res.push_back(-1);
            else
            res.push_back(it);
        }
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
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends