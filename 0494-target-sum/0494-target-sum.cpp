class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int t) {
        int sum=0;
        
        for(auto it:nums)
            sum+=it;
        if((sum+t)%2 !=0 || t+sum<0)
            return 0;
        int x=(sum+t)/2;
        vector<vector<int>> dp(nums.size()+1 ,vector<int> (x+1,-1));
        
       return help(nums,(t+sum)/2,nums.size(),dp); 
    }
    int help(vector<int>& nums,int t,int n,vector<vector<int>> &dp)
    {
        if(n==0 && t==0)
            return 1;
        if(n==0)
            return 0;
        if(dp[n][t]!=-1)
            return dp[n][t];
        
      if(t-nums[n-1]>=0)
      {
          return dp[n][t]=help(nums,t-nums[n-1],n-1,dp)+help(nums,t,n-1,dp);
      }
        return dp[n][t]= help(nums,t,n-1,dp);
        
    }
};