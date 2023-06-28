class Solution {
public:
    bool ans;
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        vector<vector<int>> gr(n+1);
        ans = true;
        for(auto it:d)
        {
            gr[it[0]].push_back(it[1]);
            gr[it[1]].push_back(it[0]);
        }
        vector<int> vis(n+1);
        vector<int> c(n+1);
        for(int i = 1;i<n+1;i++)
        {
            if(vis[i] == 0)
                 dfs(gr,vis,c,i,1,-1);
        }
        return ans;
    }
    void dfs(vector<vector<int>> &gr , vector<int> &vis ,vector<int> &c, int node ,int col,int par)
    {
        
        vis[node]  =1;
        c[node] =col; 
        
        for(auto it: gr[node])
        {
            int adj = it;
            
           if(vis[adj]==0)
            {
                c[adj] = -1*col;
             dfs(gr,vis,c,adj,-1*col,par);
            }
            else if(vis[adj]==1 && c[adj] == c[node] && par!=adj)
                ans = false;
                
            
        }
        
    }
};