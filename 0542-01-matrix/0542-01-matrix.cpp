class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dist(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>> visited(mat.size(),vector<int>(mat[0].size(),0));
        
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
        
        
        int dx[]={-1,0,+1,0};
        int dy[]={0,+1,0,-1};
        
        while(q.size()>0)
        {
                int x=q.front().first.first;
                int y=q.front().first.second;
                int d=q.front().second;
                q.pop();
                dist[x][y]=d;
                visited[x][y]=1;
                
                for(int i=0;i<4;i++)
                    {
                        int nx=x+dx[i];
                        int ny=y+dy[i];
                if(nx>=0 && nx<mat.size() && ny>=0 && ny<mat[0].size() && visited[nx][ny]==0)
                {
                   q.push({{nx,ny},d+1});
                    visited[nx][ny]=1;
                }
             }
                    
                
            }      
       
        
         
        return dist;
    }
 
};