class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& e, int dist) {
        vector<vector<int>> g(n,vector<int>(n,1e9));
        
        for(auto it:e)
        {
            g[it[0]][it[1]] = it[2];
            g[it[1]][it[0]] = it[2];
        }
        for(int i=0;i<n;i++)
            g[i][i] =0;
        
        for(int k = 0; k<n ;k++)
        {
            for(int i= 0;i<n;i++)
            {
                for(int j= 0;j<n;j++)
                {
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
        int temp=n,res=0;
        
        for(int i = 0;i<n;i++)
        {
            int cnt = 0;
            for(int j =0;j<n;j++)
            {
                if(g[i][j]<=dist)
                    cnt++;
            }
            if(temp>=cnt)
            {
            temp = cnt;
                res=i;
            }
            
        }
       // int x = *min_element(res.begin(),res.end());
        
        return res;
    }
};