#define ll long long
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& e) {
        vector<vector<int>> g(n);
        for(auto it : e)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<int> vis(n);
        
        vector<int> opt;
        
        for(int i= 0 ;i < n;i++)
        {
            if(vis[i]==0)
            {
                opt.push_back(dfs(g,vis,i));
            }
        }
        for(auto it:opt)
            cout<<it<<" ";
        
        ll ans = 0;
        ll tot = 0;
        
        for(int i =0;i<opt.size();i++)
        {
            ans+= (ll)opt[i] * (ll)(n-tot-opt[i]);
            tot+=opt[i];
            
        }
        
        return ans;
    }
    int dfs(vector<vector<int>> &g , vector<int> &vis ,int node )
    {
        // cout<<node;
        if(vis[node] ==1)
            return 0;
        
        vis[node] = 1;
        
        int ans = 1;
        
        for(auto it:g[node])
        {
            if(vis[it]==0)
            {
             ans+=dfs(g,vis,it);    
            }
        }
        return ans;
    }
};