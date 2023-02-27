class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        
        vector<int> visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(visited[i]!=0)
                continue;
            
        queue<pair<int,int>> q;
        q.push({i,1});
        while(q.size()>0)
        {
            int node=q.front().first;
            int color=q.front().second;
            q.pop();
            
            for(int i=0;i<g[node].size();i++)
            {
                if(visited[g[node][i]]==color)
                    return false;
                
                 if(visited[g[node][i]]==0)
                {
                    visited[g[node][i]]=(-1*color);
                    q.push({g[node][i],(-1*color)});
                }
            }
            
        }
    }
        
        return true;
    }
};