class Solution {
public:
    #define mod 1000000007
    int num;
    int numberOfPaths(vector<vector<int>>& g, int k) {
        num=k;
        int m=g.size();
        int n=g[0].size();  
 vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1,-1)));
        
        return help(g,0,0,0,dp)%mod;
        
    }
    int help(vector<vector<int>>& g,int i,int j,int currrem,vector<vector<vector<int>>> &dp)
    {
        if(i>=g.size() || j>=g[0].size() || j<0 || i<0)
            return 0;
        
        if(i==g.size()-1 && j==g[0].size()-1)  
        {   
            if((currrem+g[i][j])%num==0) 
                return 1;
            else
                return 0;
        } 
        if(dp[i][j][currrem]!=-1)
            return dp[i][j][currrem];
       
        
        int x=help(g,i+1,j,(currrem+g[i][j])%num,dp)%mod;
        int y=help(g,i,j+1,(currrem+g[i][j])%num,dp)%mod;
         return dp[i][j][currrem]=(x+y)%mod;
    }
};