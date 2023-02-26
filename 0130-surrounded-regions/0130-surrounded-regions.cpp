class Solution {
public:int n,m;
    
   
    void solve(vector<vector<char>>& b) {
        n=b.size();
        m=b[0].size();
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if((i==0 || j==0 || i==n-1 || j==m-1) && b[i][j]=='O')
                   dfs(b,i,j);
        
       for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(b[i][j]=='1')
                    b[i][j]='O';
                 else
                     b[i][j]='X';
          
    }
    void dfs(vector<vector<char>>& b,int i,int j)
    {
        if(i<0 || i>=n || j<0 || j>=m || b[i][j]=='X' || b[i][j]=='1')
            return ;
        
        if(b[i][j]=='O')
            b[i][j]='1';
            
        
        int dx[4]={1,0,-1,0};
         int dy[4]={0,1,0,-1};
        
        for(int k=0;k<4;k++)
         dfs(b,i+dx[k],j+dy[k]);
        
       
    }
};