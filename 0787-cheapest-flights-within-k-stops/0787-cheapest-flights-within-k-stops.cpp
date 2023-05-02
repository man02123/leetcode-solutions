class Solution {
public:typedef pair<int,int> pi;
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<vector<int>> graph[n+1];
        for(auto it:f)
        {
           graph[it[0]].push_back({it[1],it[2]}) ;
        }
        priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> pq;
        
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