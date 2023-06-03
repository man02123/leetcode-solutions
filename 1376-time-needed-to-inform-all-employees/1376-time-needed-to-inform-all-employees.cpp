class Solution {
public:
    int numOfMinutes(int n, int head, vector<int>& m, vector<int>& t) {
        vector<vector<int>> graph(n+1);
        
        for(int  i = 0; i <n;i++ )
        {
            if(m[i]!=-1)
            graph[m[i]].push_back(i);   
        }
      vector<int> vis(n+1);
       int ans = 0;
        
        for(int i = 0;i<n;i++)
        {
            if(m[i]==-1)
                ans += dfs(graph,t,i,vis);
        }
        
        
        return ans+t[head];
    }
    int dfs(vector<vector<int>> &graph ,vector<int> &t,int node,  vector<int> &vis){
        
        
        vis[node]  = 1;
        int ans = 0;
        for(auto it: graph[node])
        { 
            if(vis[it]==0)
            ans = max(ans,t[it]+dfs(graph,t,it,vis));
        }
        return ans;
        
    }
};