class Solution {
public:
    int maxMoves(vector<vector<int>>& g) {
        int m = g.size();
        int n  = g[0].size();
        vector<int> dx ={-1,0,+1};
        vector<int> dy = {-1,-1,-1};
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        // for(int i=0;i<m;i++)
        //     dp[i][0] = 1;
        int ans = 0;
        
        for(int col = 0;col<n;col++)
        {
            for(int row =0;row<m;row++)
            {
                for(int i=0;i<3;i++)
                {
                    int nx = row+dx[i];
                    int ny = col+dy[i];
                    
                    if(nx>=0 && ny>=0 && nx<m && ny<n && g[nx][ny]<g[row][col])
                    {
                        // if(row ==2 && col ==3 && nx==1 && ny==2)
                        //     cout<<"yes"<<dp[nx][ny];
                        
                        if(ny>0  && dp[nx][ny]==0 && dp[row][col]==0)
                            dp[row][col]  =0;
                        else
                        dp[row][col] = max(dp[row][col] , 1+dp[nx][ny]);
                    }
                    
                }
                 
                        ans = max(ans,dp[row][col]);
                
            }
        }
        // for(auto it:dp)
        // {
        //     for(auto it2:it)
        //         cout<<it2;
        //     cout<<endl;
        // }
        return ans;
        
    }
};

// class Solution {
// public:
//     int res;
//     int maxMoves(vector<vector<int>>& g) {

//          res = 0;
        
//             for(int j=0;j<g.size();j++)
//             {
//                 dfs(g,j,0,0);
//             }
        
//         return res;
//     }
//     bool isvalid(vector<vector<int>>& g,int i,int j)
//     {
//        if(i<0 || i>=g.size() || j<0 || j>=g[0].size() || g[i][j]==-1)
//            return false;
//         return true;
//     }
    
//     void dfs(vector<vector<int>>& g,int i,int j,int step)
//     {
//         if(i<0 || i>=g.size() || j<0 || j>=g[0].size() || g[i][j] ==-1)
//             return ;
//         if(dp[i][j]!=-1 && g[i][j])
        
        
//         if(isvalid(g,i-1,j+1)==true && g[i-1][j+1]>g[i][j] )
//         {
//             //cout<<"err"<<i<<j<<" ";
        
//             int x = g[i][j];
//             g[i][j] =-1;
            
//             res=max(step+1,res);
//             dfs(g,i-1,j+1,step+1);
//             g[i][j] = x;
//         }
//          if(isvalid(g,i,j+1)==true && g[i][j+1]>g[i][j])
//         {
            
//             int x = g[i][j];
//              g[i][j] =-1;
//             res=max(step+1,res);
//             dfs(g,i,j+1,step+1);
//             g[i][j] = x;
//         }
//          if(isvalid(g,i+1,j+1)==true && g[i+1][j+1]>g[i][j])
//         {
//             int x = g[i][j];
//              g[i][j] =-1;
//             res=max(step+1,res);
//             dfs(g,i+1,j+1,step+1);
//             g[i][j] = x;
//         }
            
        
//     }
// };