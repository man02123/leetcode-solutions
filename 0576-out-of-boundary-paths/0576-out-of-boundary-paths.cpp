class Solution {
public:int mx;
    vector<int> dx={0 , 0,+1,-1};
    vector<int> dy={+1 , -1,0,0};
    int memo[51][51][51];
    int findPaths(int m, int n, int mm, int sr, int sc) {
        mx = mm;
        memset(memo, -1,sizeof(memo));
        
       // vector<vector<int>> vis(m, vector<int>(n,0));
        int ans=0;
        // for(int i =1;i<=mx;i++)
        // ans +=
        return solve(m, n ,0 , sr , sc);
        return ans;
    }
    int solve(int m , int n , int cm , int sr , int sc){
         if(cm >mx )return 0;
       int mod = 1000000000+7;
        if((sr< 0 || sc<0 ||sc>=n || sr>=m ) ){
            return 1;
        }
        if(memo[cm][sr][sc]!=-1)return memo[cm][sr][sc];
        
        int ans = 0;
        
        for(int i =0;i<4;i++){
             
            int nx = sr+dx[i];
            int ny = sc+dy[i];
            //cout<<nx<<ny<<" ";
            ans = (ans+(solve(m  , n , cm+1, nx , ny))%mod)%mod;
            ans = (ans)%mod;
 
        }
        
        return memo[cm][sr][sc]=(ans)%mod;
    }
};