class Solution {
public:vector<int> dx,dy;
    typedef pair<int,int> pi;
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        dx = {-1,-1,0,1,1,1,0,-1};
        dy = {0,1,1,1,0,-1,-1,-1};
        
        queue<pair<int,pi>> q;
        q.push({1,{0,0}});
    vector<vector<int>> vis(g.size(),vector<int>(g[0].size(),0));
        vis[0][0] =1;
        if(g[0][0]==1)
            return -1;
        if(g[g.size()-1][g[0].size()-1] ==1)
            return -1;
        
        while(!q.empty())
        {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int d =q.front().first;
            if(x==g.size()-1  && y==g[0].size()-1)
                return d;
            q.pop();
            
            for(int i =0 ;i<8;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx>=0 && nx<g.size() && ny>=0 && ny<g[0].size() && vis[nx][ny]==0 &&g[nx][ny]!=1)
                {
                    vis[nx][ny] = 1;
                    q.push({1+d,{nx,ny}});
                }
                
            }
            
            
        }
        return -1;
        
    }
};