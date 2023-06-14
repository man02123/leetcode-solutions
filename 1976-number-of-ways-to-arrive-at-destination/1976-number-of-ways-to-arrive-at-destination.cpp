#define pi pair<long long,long long>
class Solution {
public:
    
    int countPaths(int n, vector<vector<int>>& r) {
        vector<vector<pair<long long ,long long>>> g(n);
        for(auto it:r)
        {
           g[it[0]].push_back({it[1],it[2]});
           g[it[1]].push_back({it[0],it[2]}); 
        }
        vector<long long> dist(n,LONG_MAX);
        vector<long long> ways(n,0);
        priority_queue<pi , vector<pi> ,greater<pi>> pq;
        
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0,0});
        
        while(!pq.empty()){
            long long node  = pq.top().second;
           long long d = pq.top().first;
            pq.pop();
            for(auto it:g[node]){
                int adj = it.first;
                int eW = it.second;
                
                if(d + eW <dist[adj]){
                    dist[adj] = d + eW;
                    ways[adj] = ways[node] ;
                    pq.push({d + eW , adj});
                }
                else if(d + eW ==dist[adj]){
                    ways[adj] =(ways[adj]+ ways[node])%(long long)(1e9+7);
                }
            }
            
        }
        return  ways[n-1];
    }
};