class Solution {
public:vector<int> dx,dy;
    int n;
    int shortestBridge(vector<vector<int>>& g) {
        dx = {1,0,0,-1};
        dy = {0,1,-1,0};
        
        vector<vector<int>> vis2(g.size(),vector<int> (g.size(),0));
       
        n = g.size();
        
        int r,c;
        bool check = true;
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(g[i][j] == 1)
                {
                    r=i;
                    c=j;
                  check = false;
                }
                
            }
            if(check==false)
                    break;
        }
        
         dfs(g,r,c);
        
        queue<pair<pair<int,int>,int>> q;
        
        
        int x = 0;
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(g[i][j]==2)
                    q.push({{i,j},0});    
            }
        }
        
        while(q.size()>0)
        {
           int x = q.front().first.first;
            int y = q.front().first.second;
            int flip = q.front().second;
            q.pop();
            
            for(int i =0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx>=0 && ny>=0 && nx<n && ny<n)
                {
                    if(g[nx][ny] == 0)
                    {
                        q.push({{nx,ny},flip+1}) ;
                        g[nx][ny] = 2;
                    }
                    else if(g[nx][ny] == 1)
                    {
                        return flip;
                    }
                } 
                
               } 
            }
        
        return x;
        
    }
    void dfs(vector<vector<int>> &g,int row,int col)
    {
        if(row<0 || col<0 || row>=n || col>=n || g[row][col]==2)
            return;
        
    
        if(g[row][col] ==1)
        {
            g[row][col] =2;
            for(int i=0;i<4;i++)
            {
                int nx = row+dx[i];
                int ny = col+dy[i];
                dfs(g,nx,ny);
            }
        }
   
    }
    
//     int bfs(vector<vector<int>> &g,int r,int c,vector<vector<int>> &vis2)
//     {
        
        
        
//         // g[x][y] = 3;
//         bool flag = false;
//         int ans;
        
        
//         return ans;
        
//     }
};