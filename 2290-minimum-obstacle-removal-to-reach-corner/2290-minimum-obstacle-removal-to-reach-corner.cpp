#define pi pair<int,pair<int,int>> 
class Solution {
public:int n,m;
    bool isvalid(int x , int y){
        if(x>=0 && y>=0 && x<m && y<n)
            return true;
        return false;
    }
    int minimumObstacles(vector<vector<int>>& g) {
      m = g.size();
        n = g[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e8));
        dist[0][0] = 0;
        
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
       pq.push({0,{0,0}});
        while(!pq.empty()){
            int ob = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
           // cout<<x<<y<<" ";
            for(int i = 0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(isvalid(nx,ny)){
                  if(g[nx][ny] == 1  && dist[nx][ny]>ob+1)
                  {
                      dist[nx][ny] = 1+ob;
                      if(nx == m-1 && ny ==n-1)
                          return dist[nx][ny];
                      pq.push({dist[nx][ny],{nx,ny}});
                  }
                    else if( g[nx][ny] == 0  && dist[nx][ny]>ob)
                    {
                        dist[nx][ny] = ob;
                        if(nx == m-1 && ny ==n-1)
                          return dist[nx][ny];
                        pq.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
  
        }
         return dist[m-1][n-1];
        
    }
};