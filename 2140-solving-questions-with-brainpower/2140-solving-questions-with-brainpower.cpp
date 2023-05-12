class Solution {
public:vector<long long> dp;
    long long mostPoints(vector<vector<int>>& q) {
        dp.resize(q.size(),-1);
        return solve(q,0);
        
    }
    long long solve(vector<vector<int>>& q , int ind )
    {
        if(ind>=q.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        
        
            long long sol= q[ind][0]+solve(q,ind+q[ind][1]+1);
             long long nsol = solve(q,ind+1); 
        
        return dp[ind] = max(sol,nsol);
        
    }
};