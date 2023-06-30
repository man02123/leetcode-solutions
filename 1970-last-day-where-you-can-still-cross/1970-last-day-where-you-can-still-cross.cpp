// class Solution {
// public:
//     vector<int> dx = {0,1,-1,0};
//     vector<int> dy = {1,0,0,-1};
       
//     int latestDayToCross(int row, int col, vector<vector<int>>& c) {
//        int l =0,r=c.size()-1;
        
//         vector<vector<int>> m(row,vector<int>(col,0));
//         dx = {-1,1,0,0};
//         dy = {0,0,1,-1};
//         int ans= 0;
        
//         while(l<=r)
//         {
//             int mid = l + (r-l)/2;
//             set<pair<int,int>> st;
            
//             for(int i =0;i<mid;i++)
//             {
//                 st.insert({c[i][0]-1,c[i][1]-1});
//             }
//             if(bfs(m,st)==true)
//             {
//                 ans= max(ans,mid);
//                 l=mid+1;
//             }
//             else
//                 r = mid-1;
            
//         }
//         return ans;
        
        
//     }
//     bool bfs(vector<vector<int>> &m ,set<pair<int,int>>&st)
//     {
        
//         queue<pair<int,int>> q;
//          vector<vector<int>> vis(m.size(),vector<int>(m[0].size(),0));
        
        
//         for(int i =0;i<m[0].size();i++)
//         {
            
//             if(st.find({0,i}) == st.end())
//             {
//                 q.push({0,i});
//                 //vis[0][i] = 1;
                
//             }
//         }
       
        
//         while(!q.empty())
//         {
//             int x = q.front().first;
//             int y = q.front().second;
//             q.pop();
//             cout<<x<<y<<" ";
            
//             if(x==m.size()-1 && y==m[0].size()-1)
//                 return true;
            
//             vis[x][y] = 1;
            
//             for(int i = 0;i<4;i++)
//             {
//                 int nx = x+dx[i];
//                 int ny=  y+dy[i];
                
//                 if( val(nx,ny,m) && st.find({nx,ny})==st.end() && vis[nx][ny] ==0)
//                 {
//                     q.push({nx,ny});
//                 }
//             }   
            
//         }
//         cout<<endl;
//         return false;
//     }
    
//     bool val(int x,int y,vector<vector<int>> &m)
//     {
//         if(x>=0 && y>=0 && x<m.size() && y<m[0].size())
//             return true;
        
//         return false;
//     }
// };
class Solution {
public:
    int n,m;
    int d[5] = {0,1,0,-1,0};
    bool dfs(vector<vector<int>>&vis,vector<vector<int>>&v,int i,int j){
        vis[i][j]=1;
        if(i==n-1)return true;
        bool ans = false;
        for(int k=0;k<4;k++){
            int ni = i + d[k];
            int nj = j + d[k+1];
            if(ni>=0 && nj>=0 && ni<n && nj<m && !vis[ni][nj] && !v[ni][nj]){
                ans |= dfs(vis,v,ni,nj);
            }
        }
        return ans;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cell) {
        int l=0,r=cell.size()-1;
        n = row;
        m = col;
        int day=0;
        while(l<=r){
            int mid = (l+r)/2;
            vector<vector<int>>v(row,vector<int>(col,0));
            for(int i=0;i<=mid;i++){
                v[cell[i][0]-1][cell[i][1]-1]=1;
            }
           vector<vector<int>>vis(row,vector<int>(col,0));
           bool ans=false;
           for(int i=0;i<col;i++){
               if(vis[0][i]==0 && v[0][i]==0){
                   ans |= dfs(vis,v,0,i);
               }
           }
           if(ans){
               day=mid;
               l=mid+1;
           }
           else{
               r = mid - 1;
           }
        }
        return day+1;
    }
};