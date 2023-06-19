class Solution {
public:int dp[501][501];
    int paintWalls(vector<int>& cost, vector<int>& t) {
        memset(dp,-1,sizeof(dp));
        return solve(cost ,t, 0,cost.size());
    }
    int solve(vector<int>& co, vector<int>& t , int ind , int tim){
        
        if(tim<=0)
            return 0;
       
        if(ind>=co.size())
            return 1000000000;
        if(dp[ind][tim]!=-1)
            return dp[ind][tim];
        
        int ftake=INT_MAX,ptake=INT_MAX;
        
           ptake = co[ind] +solve(co,t,ind+1,tim-t[ind]-1);
         
            ftake = solve(co,t,ind+1,tim);
            
        
         return dp[ind][tim] = min(ftake,ptake);;
    }
};