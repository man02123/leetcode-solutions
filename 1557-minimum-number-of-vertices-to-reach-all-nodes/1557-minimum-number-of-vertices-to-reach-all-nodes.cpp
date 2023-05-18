class Solution {
public:vector<int> res;
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& e) {
        vector<int> vis(n+1,0);
        vector<int> ind(n+1,0);
        for(auto it:e)
        {
            ind[it[1]]++;
            vis[it[1]] = 1;
        }
        for(int i=0;i<n;i++)
        {
          if(!vis[i] || ind[i] ==0)
          {
              //bfs(g,i,vis);
              res.push_back(i);
          }
        } 
        return res;
    }
    void bfs(vector<vector<int>> &g,int node,vector<int> &vis)
    {
        queue<int> q;
        q.push(node);
        while(q.size()>0)
        {
            int t = q.front();
            vis[t]  =1;
            q.pop();
            
            for(auto it:g[t])
            {
                if(!vis[it])
                {
                   q.push(it); 
                }
            }
        }
        
    }
};