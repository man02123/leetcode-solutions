class Solution {
   
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int tar) {
         vector<vector<int>> dp(nums.size()+1,vector<int>(tar+1,-1));
        //memset(dp,-2,sizeof(dp));
        
        int x =  solve(nums,tar,0,0,dp);
       
        
        return (x<0) ?-1:x;
    }
    int solve(vector<int>& nums,int tar,int ind,int len,vector<vector<int>> &dp){
        
        if(ind>=nums.size()){
        if(tar == 0)return 0;
            
            return INT_MIN;
        }
        
        if(tar<0)
            return INT_MIN;
        
        if(dp[ind][tar] != -1)
            return dp[ind][tar];
        
        if(tar == 0)
            return 0;
        
        int take = INT_MIN,ntake = INT_MIN;
        
         // if(tar-nums[ind] >0)
          take = 1+solve(nums,tar-nums[ind],ind+1,len+1,dp);
        
         ntake = solve(nums,tar,ind+1,len,dp);   
        
        return dp[ind][tar] =max(take,ntake);
        
        //return dp[ind][tar] = max(dp[ind][tar] , max(take,ntake));
    }
};