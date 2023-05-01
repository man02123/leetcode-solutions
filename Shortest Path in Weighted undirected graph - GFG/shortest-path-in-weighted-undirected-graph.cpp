//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  typedef pair<int,int> pi;
    vector<int> shortestPath(int n, int m, vector<vector<int>>& e) {
        vector<pi> g[n+1];
        
        for(auto it:e)
        {
            pi temp = {it[1],it[2]};
            g[it[0]].push_back(temp);
            g[it[1]].push_back({it[0],it[2]});
        }
        vector<int> dist(n+1,1e9);
        vector<int> parent(n+1);
        
        for(int i=0;i<n+1;i++)
        parent[i] = i;
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        dist[1] = 0;
        pq.push({0,1});
        
        while(pq.size()>0)
        {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            for(auto it:g[node])
            {
                int adjnode = it.first;
                int adjdist = it.second;
                if(adjdist+d<dist[adjnode])
                {
                    pq.push({adjdist+d,adjnode});
                    dist[adjnode] = adjdist+d;
                    parent[adjnode] = node;
                }
            }
        }
        if(dist[n] ==1e9 )
        return {-1};
        
        vector<int> res;
        res.push_back(n);
        
        int ind = n;
        
        while(parent[ind]!=ind)
        {
            res.push_back(parent[ind]);
            ind = parent[ind];
        }
        reverse(res.begin(),res.end());
        return res;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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