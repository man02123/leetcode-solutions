#define pi pair<int,pair<int,int>> 
class Solution {
public:
    vector<int> dx,dy;
     
    int orangesRotting(vector<vector<int>>& g) {
        dx = {-1,0,1,0};
        dy = {0,-1,0,1};
        vector<vector<int>> vis(g.size(),vector<int> (g[0].size(),0));
        
        queue<pi> q;
        
        for(int i = 0;i<g.size();i++)
        {
            for(int j = 0;j<g[0].size();j++)
            {
                if(g[i][j]==2)
                {
                    q.push({0,{i,j}});
                    vis[i][j]=2;
                }
            }
        }
        
        int ans = 0;

        while(q.size()>0)
        {
            
            int k = q.size();
            
            int t = q.front().first;
            int x = q.front().second.first;
            int y  =q.front().second.second;
            q.pop();
                ans = max(ans,t);
            for(int i = 0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx>=0 && nx<g.size() && ny>=0 && ny<g[0].size() && vis[nx][ny]!=2 && g[nx][ny]==1){
                    vis[nx][ny] = 2;
                    q.push({t+1,{nx,ny}});
                    
                }
            }
            
        }
        bool flag = true;
        
         for(int i=0;i<g.size();i++)
            for(int j=0;j<g[0].size();j++)
                if(g[i][j]==1 && vis[i][j]!=2)return -1;
        
        
        return (flag == false)?-1:ans;
        
        
    }
};