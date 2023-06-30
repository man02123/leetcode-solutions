class Solution {
public:
    vector<int> dx = {0,1,-1,0};
    vector<int> dy = {1,0,0,-1};
       
    int latestDayToCross(int row, int col, vector<vector<int>>& c) {
       int l =0,r=c.size()-1;
        
        int ans= 0;
        
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            vector<vector<int>> m(row,vector<int>(col,0));
            
            for(int i =0;i<=mid;i++)
            {
               m[c[i][0]-1][c[i][1]-1] = 1;
            }
            if(bfs(m)==true)
            {
                ans= mid;
                l=mid+1;
            }
            else
                r = mid-1;
            
        }
        return ans+1;
        
        
    }
    bool bfs(vector<vector<int>> &m)
    {
        
        queue<pair<int,int>> q;
         vector<vector<int>> vis(m.size(),vector<int>(m[0].size(),0));
        
        
        for(int i =0;i<m[0].size();i++)
        {
            
            if(m[0][i] == 0)
            {
                q.push({0,i});
                //vis[0][i] = 1;
                
            }
        }
       
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            //cout<<x<<y<<" ";
            
            if(x==m.size()-1)
                return true;
            
            
            
            for(int i = 0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny=  y+dy[i];
                
                if( val(nx,ny,m) && m[nx][ny]==0 && vis[nx][ny] ==0)
                {
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }   
            
        }
       // cout<<endl;
        return false;
    }
    
    bool val(int x,int y,vector<vector<int>> &m)
    {
        if(x>=0 && y>=0 && x<m.size() && y<m[0].size())
            return true;
        
        return false;
    }
};
