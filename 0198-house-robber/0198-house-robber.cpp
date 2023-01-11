class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums.size()+1,-1);
       return solve(nums,n-1,dp);
        
    }
    int solve( vector<int> &nums,int ind, vector<int> &dp )
    {
        if(ind==0)return dp[0]=nums[0];
        //if(ind==1) return dp[1]=nums[1];
        
        if(ind<0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        
        int last=nums[ind]+solve(nums,ind-2,dp);
        int seclast=nums[ind-1]+solve(nums,ind-3,dp);
        return dp[ind]=max(last,seclast);
    }
};