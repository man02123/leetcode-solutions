class Solution {
public:
    int dp[201][101*201];
    bool canPartition(vector<int>& n) {
        int sum = 0;
        int s1 = accumulate(begin(n),end(n),0);
        
        if(s1 %2 !=0)return false;
        
        memset(dp,-1,sizeof(dp));
        return solve(n,0,s1/2);
    }
    bool solve(vector<int>& n , int ind,int sum){
        
        if(sum == 0)return true;
       if(ind >= n.size())return false;
        if(sum < 0)return false;
        
        if(dp[ind][sum] != -1)return dp[ind][sum];
        
        bool ans = false;
        
        ans |= (solve(n , ind+1,sum - n[ind])|solve(n,ind+1,sum));
        
        return dp[ind][sum] = ans;
    }
};