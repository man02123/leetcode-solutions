class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& e, vector<int>& r) {
        
        vector<vector<int>> g(n);
        
        for(auto it:e)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
            
        }
        
        vector<int> vis(n+1);
        vector<int> res(n+1);
        for(auto it:r)
            res[it]++;
      
                dfs(g,vis,res,0);
                
        int cnt=0;
        for(auto it:vis)
            if(it==1)cnt++;
        
        return cnt;
    }
    void dfs(vector<vector<int>> &g,vector<int> &vis,vector<int> &res,int node)
    {
        vis[node]=1;
        for(auto it: g[node]){
            if(!vis[it]  && res[it]==0)
                dfs(g,vis,res,it);
        }
    }
};