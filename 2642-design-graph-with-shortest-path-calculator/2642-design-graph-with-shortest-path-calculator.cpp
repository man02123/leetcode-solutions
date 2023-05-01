class Graph {
public:unordered_map<int, vector<pair<int, int>>> graph;
    
    Graph(int n, vector<vector<int>>& e) {
       for(auto it:e)
       {
          graph[it[0]].push_back({it[1],it[2]});
       }
        
    }
    
    void addEdge(vector<int> e) {
        graph[e[0]].push_back({e[1],e[2]});
    }
    
    int shortestPath(int n1, int n2) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist (101);
        for(int i=0;i<dist.size() ; i++)
            dist[i] = 1e9;
        
        pq.push({0,n1});
        dist[n1] = 0;
        
        while(pq.size()>0)
        {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto it:graph[node])
            {
                int adjnode = it.first;
                int newdist = it.second;
                
                if(d+newdist<dist[adjnode])
                {
                  dist[adjnode] =  d+newdist;
                    pq.push({d+newdist,adjnode});
                }
                
            }
        }
        return (dist[n2]==1e9)?-1:dist[n2];
        
//         vector<int> res;
//         res.push_back(0);
//         res.push_back(dist[n2]);
//         return res;
        
        
        return 0;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */