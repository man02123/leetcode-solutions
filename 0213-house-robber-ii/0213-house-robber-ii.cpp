class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size()+1,-1);
        
       int nl = solve(nums,nums.size()-2,0,dp);
        
        vector<int> dp2(nums.size()+1,-1);
        int l = solve(nums , nums.size()-1,1,dp2);
        
        return max(nl,l);
    }
    int solve(vector<int>& nums , int ind,int st,vector<int>&dp){
        if(st==1  && ind == 0)
            return 0;
        
         if(ind < 0)
             return 0;
            if(dp[ind] != -1)
                return dp[ind];
        int t = -1,nt=-1;
           
           t = nums[ind] + solve(nums,ind-2,st,dp);
           nt = solve(nums , ind-1,st,dp);
        
        return dp[ind] = max(t,nt);
        
    }
};