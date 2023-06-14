#define pi pair<int, pair<int,int>>

class Solution {
public:vector<int> dx;
       vector<int> dy;
    
    int minimumEffortPath(vector<vector<int>>& h) {
        dx={-1,0,1,0};
        dy={0,1,0,-1};
        int m = h.size();
        int n = h[0].size();
        
        vector<vector<int>> dist(h.size(),vector<int>(h[0].size(),INT_MAX));
        
        dist[0][0]  =0;
    priority_queue<pi , vector<pi> , greater<pi>> pq;
        
        pq.push({0,{0,0}});
        int ans= 0;
        while(pq.size()>0){
            
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            
            int pmin = pq.top().first;
            // if(x==m-1 && y==n-1)
            //     return pmin;
            pq.pop();

            for(int i = 0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
  
                if(nx>=0 && ny>=0 && nx<m && ny<n){
                    
                     int nval = h[nx][ny];
                     int pval = h[x][y];
                     int diff = max(abs(pval-nval),pmin);

                      if(diff< dist[nx][ny]){
                       dist[nx][ny] = diff;
                          pq.push({diff,{nx,ny}});
                      }
                    
                    
                }
                
            }
            
            
        }
        return dist[m-1][n-1];  
    }
 
};