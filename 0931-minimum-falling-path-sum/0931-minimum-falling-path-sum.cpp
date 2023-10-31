class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int r = m.size();
        int c =  m[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(r+1,vector<int>(c+1,INT_MAX));
        for(int j = 0;j<m[0].size();j++){
         ans = min(ans,solve(m,r-1,j,dp));   
        }
       return ans; 
    }
    int solve(vector<vector<int>>& m , int row,int col,vector<vector<int>> &dp){
       
        if(col <0 || col>=m[0].size() || row<0)return 100000;
        if(row == 0 && col>=0 && col<m[0].size())return m[row][col];
        
        if(dp[row][col] != INT_MAX)
            return dp[row][col];
        int ans = 0;
        ans = m[row][col] +min({solve(m,row-1,col,dp),solve(m,row-1,col-1,dp),solve(m,row-1,col+1,dp)});
        return dp[row][col]=ans;
    }
};