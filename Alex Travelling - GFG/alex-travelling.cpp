//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:  
    int minimumCost(vector<vector<int>>& t, int n, int k) {
        vector<vector<int>> graph[n+1];
        
        for(auto it:t)
        {
            graph[it[0]].push_back({it[1],it[2]});
        }
        vector<int> visited (n+1,0);
        vector<int> res(n+1,INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,k});
        visited[k] =1;
        res[k] = 0;
        
        while(!pq.empty())
        {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            
            for(auto it:graph[node])
            {
                int adjnode = it[0];
                int tt =it[1];
                if(visited[adjnode] ==0)
                {
                    res[adjnode] = time+tt;
                    pq.push({time+tt,adjnode});
                    visited[adjnode] = 1;
                }
                else
                {
                    if(time+tt<res[adjnode])
                    {
                       res[adjnode] = time+tt;
                       pq.push({time+tt,adjnode}); 
                    }
                }
            }
        }
        int x = -1;
        for(int i=1;i<=n;i++)
            x = max(x,res[i]);
        
        return (x==INT_MAX)?-1:x;
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends