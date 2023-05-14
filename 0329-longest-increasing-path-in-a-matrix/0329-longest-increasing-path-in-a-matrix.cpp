class Solution {
public:
    int rs,cs;
    vector<int> dx;
    vector<int> dy;
    
    int memo[301][301];
    
    int longestIncreasingPath(vector<vector<int>>& m) {
        memset(memo,-1,sizeof(memo));
        rs =m.size();
        cs =m[0].size();
        
        dx ={1,-1,0,0};
        dy ={0,0,1,-1};
        //vector<vector<int>> vis(m.size(),vector<int>(m[0].size(),0));
        
        int res= 0;
        for(int i =0;i<m.size();i++)
        {
            for(int j = 0;j<m[0].size();j++)
            {
                int x = dfs(m,i,j);
                res = max(res,x);
            }
        }
        return res;
    }
    bool isvalid(int nx,int ny)
    {
        if(nx<0 || ny<0 || nx>=rs || ny>=cs)
            return false;
        return true;
        
    }

    int dfs(vector<vector<int>> &m,int r,int c)
    {
        
        if(memo[r][c] != -1)
            return memo[r][c];
        
        
        int ans = 1;
        for(int i = 0;i<4;i++)
        {
            int nx = r + dx[i];
            int ny = c + dy[i];
            
            if( isvalid(nx,ny)==true && m[nx][ny]>m[r][c])
             ans = max(ans,1+dfs(m,nx,ny));
            
        }
        return memo[r][c]= ans;
        
    }
    
};
