class Solution {
public:
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {

        vector<int> vis(n,0);
        vector<vector<int>> g(n);
        
        for(int i= 0;i<e.size();i++)
        {
           g[e[i][0]].push_back(e[i][1]) ;
           g[e[i][1]].push_back(e[i][0]) ; 
        }
        
        queue<int> q;
        q.push(s);
        vis[s] =1;
        
    while(q.size()>0)
    {
        int node = q.front();
       
        q.pop();
        if(node  == d)
            return true;
        for(auto it:g[node])
        {
            if(vis[it] ==0)
            {
                q.push(it);
                 vis[it] = true;
            }
        }
        
    }
        return false;
        
    }
};