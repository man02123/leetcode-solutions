class Solution {
public:
    int findCircleNum(vector<vector<int>>& g) {
        
    int  cnt = 0;
        int n = g.size();
        vector<vector<int>> graph(n); 
        
        for(int i = 0;i<g.size();i++)
        {
            for(int j = 0;j<g.size();j++)
            {
                if(g[i][j] ==1  && i!=j)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
                    
            }
        }
        
//         for(auto it:graph)
//         {
//             for(auto it2:it)
//                 cout<<it2;
//             cout<<"\n";

//         }
        
        
        vector<int> vis(n);
        
        for(int i = 0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                //cout<<i;
                dfs(graph,i,vis);  
                cnt++;
             }
        }
        return cnt;
  
    }
    
    void dfs( vector<vector<int>> &graph ,  int node , vector<int> &vis)
    {
       
        vis[node] = 1;
        
        for(auto it:graph[node])
        {
            if(vis[it] == 0 )
                dfs(graph, it,vis);
        }
        
    }
            
};