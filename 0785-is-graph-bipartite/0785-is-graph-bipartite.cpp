class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        
        //vector<int> visited(n,0);
        vector<int> col(n,0);
        bool ans = true;
        for(int i = 0;i<n;i++)
        {
            if(col[i] == 0)
             ans &=dfs(g,i,1,col);   
        }
        
        return ans;
    }
    bool dfs(vector<vector<int>>& g , int node,int parcol,vector<int> &col)
    {
        if(col[node] !=0)
        {
            if(col[node] != parcol)
                return false;
            return true;
        }
        bool ans = true;
        
        col[node] = parcol;
        
        
        for(auto adj: g[node])
        {
            ans &= dfs(g,adj,-1* parcol,col);
            
        }
        return ans;
    }
};