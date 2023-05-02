//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public://pair<int,int> pi;
    int CheapestFLight(int n, vector<vector<int>>& f, int src, int dst, int k)  {
        vector<vector<int>> graph[n+1];
        for(auto it:f)
        {
           graph[it[0]].push_back({it[1],it[2]}) ;
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{src,0}});
        
        vector<int> ctake(n,INT_MAX);
        
        ctake[src] = 0;
        
        int stop = 0;
        while(stop<=k && pq.size()>0)
        {
            int x =pq.size();
            stop++;
            while(x--)
            {
            int node =pq.top().second.first;
            //int stops =pq.top().second.second;
            int cost = pq.top().second.second;
            pq.pop();
            
           for(auto it:graph[node])
           {
               int adjnode = it[0];
               int adjcst = it[1];
              if( cost+adjcst<ctake[adjnode])
              {
                  ctake[adjnode] = cost+adjcst;
                  pq.push({stop,{adjnode,cost+adjcst}});
              }
            }
            }
     
        }
        // for(auto it:ctake)
        //     cout<<it<<" ";
        if(ctake[dst] == INT_MAX)
            return -1;
                 
                 return ctake[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends