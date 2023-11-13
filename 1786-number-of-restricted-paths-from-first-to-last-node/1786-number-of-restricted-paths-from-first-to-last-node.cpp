class Solution {
public:int mod = 1e9+7;
    int countRestrictedPaths(int n, vector<vector<int>>& e) {
        vector<int> dist(n+1,INT_MAX);
        dist[n] = 0;
        vector<vector<pair<int,int>>> g(n+1);
        
        for(auto it:e){
            g[it[0]].push_back({it[1],it[2]});
            g[it[1]].push_back({it[0],it[2]});
        }
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        pq.push({0,n});
        
        while(pq.size() > 0){
            auto x  = pq.top();
            pq.pop();
            int node = x.second;
            int d = x.first;
             
            
            for(auto it:g[node]){
                int adj = it.first;
                int wt = it.second;
                
                if(wt+d < dist[adj]){
                    dist[adj] = wt+d;
                    pq.push({wt+d, adj});
                    
                }

                
            }
        }
        
        vector<int> myans(n+1,-1);
        return dfs(g,dist,n,myans);
        
    }
    int dfs(vector<vector<pair<int,int>>> &g ,vector<int> &dist,int curr,vector<int> &myans){
        if(curr == 1)return 1;
        
        if(myans[curr] !=-1)return myans[curr];
        int ans= 0;
        for(auto it:g[curr]){
            int cnode = it.first;
            if(dist[cnode] > dist[curr]){
                ans = ((ans+(dfs(g,dist,cnode,myans))%mod)%mod)%mod;
            }
        }
       return myans[curr] = ans%mod;
        
    }
    
};
