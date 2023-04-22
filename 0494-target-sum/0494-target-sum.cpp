class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int t) {
       return help(nums,t,nums.size()-1); 
    }
    int help(vector<int>& nums,int t,int n)
    {
        if(n<0 && t==0)
            return 1;
        
        if(n<0)
            return 0;
      return help(nums,t+nums[n],n-1)+help(nums,t-nums[n],n-1);
        
    }
};