class Solution {
public:vector<vector<int>> res;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vector<vector<int>> adj(n);
        
        for(auto it:c){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n);
        vector<int> tin(n,INT_MAX),low(n);
        
        dfs(adj ,vis ,tin,low, 0,-1,0);
        return res;
    }
    void dfs(vector<vector<int>>& adj , vector<int> &vis,vector<int> &tin,vector<int> &low,int node , int par,int t){
        
       vis[node] = 1;
        
        tin[node]  = t;
        low[node] = t;
        
        for(auto it:adj[node])
        {
            if(!vis[it]){
                dfs(adj,vis,tin,low,it,node,t+1);
                low[node] = min(low[node],low[it]);
                
                if(tin[node]<low[it])
                    res.push_back({node,it});
            }
            else {
                if(it!=par)
                {
                    low[node] = min(low[node],low[it]);
                }
            }
        }
        
        
        
    }
};