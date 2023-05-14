class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& e) {
        
        vector<int> vis(n,0);
        vector<vector<int>> g(n);
        for(auto it:e)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
                cnt+=bfs(g,i,vis);
        }
        return cnt;
        
    }
    int bfs(vector<vector<int>> &g,int node,vector<int> &vis)
    {
        vis[node] =1;
        queue<int> q;
        q.push(node);
        bool ans = true;
        
        unordered_map<int,int> mp;
        mp[node] =1;
        
        while(q.size()>0)
        {
            int n = q.front();
            q.pop();
            int sz= g[n].size();
            
            for(auto it:g[n])
            {
                if(mp[it]==0)
                {
                    if(vis[it]==1)
                     ans = false;
                    
                    vis[it]=1;
                    q.push(it);
                    mp[it]= 1;
                }
                
            }

        }
        if(ans!=false)
        {
        for(auto it:mp)
        {
            if(g[it.first].size() != mp.size()-1)
                ans = false;
        }
        }
        return ans==true ?1:0;
        
    }
    
    
};