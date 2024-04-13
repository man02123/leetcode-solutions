class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& e, vector<int>& dis) {
        
        vector<vector<pair<int,int>>> g(n);
        
        for(int i =0;i<e.size();i++){
            g[e[i][0]].push_back({e[i][1] ,e[i][2] });
            g[e[i][1]].push_back({e[i][0], e[i][2] });
        }
        vector<int> dist(n , INT_MAX);
        dist[0] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,0});
        vector<int> vis(n, 0);
     
        
        
        while(pq.size() > 0){
            
            int min_dis = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            
            if( vis[node] == 0){
                vis[node] = 1;
                
            for(auto it: g[node]){
                
               int n_dis = it.second;
               int adj = it.first;
                
                if(min_dis + n_dis < dis[adj] && min_dis + n_dis < dist[adj] && vis[adj]==0 ){
                    
                    dist[adj] = min_dis + n_dis;
                    pq.push({min_dis + n_dis , adj});
                }
                
            }
            }
            
        }
        
        vector<int> ans(n);
        
        for(int i =0;i<n;i++){
            if(dist[i] == INT_MAX){
                ans[i] = -1;
            }
            else
                ans[i] = dist[i];
        }
        
        
        
       return ans; 
    }
};