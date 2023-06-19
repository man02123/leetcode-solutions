class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        vector<int> dist(n+1);
        
        for(int i =0;i<=n;i++)
            dist[i] = 1e8;
        
        dist[k] = 0;
        for(int i = 1;i<=n;i++){
            
            for(auto it:t){
                int u = it[0];
                int v =it[1];
                int wt = it[2];
                
                if(dist[u]+wt<dist[v])
                    dist[v] = wt+dist[u];
                
            }
        }
        
        for(auto it = 1;it<=n;it++){
            if(dist[it]==1e8)
                return -1;
        }
        int ans = -1;
        for(auto it:dist)
            if(it!=1e8)
            ans = max(ans,it);
        
        return ans;
        
    }
};