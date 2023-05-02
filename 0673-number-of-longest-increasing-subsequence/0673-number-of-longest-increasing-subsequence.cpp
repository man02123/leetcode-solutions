class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<int> cnt(nums.size(),1);
        int maxi = 1;
        
        for(int i=0;i<nums.size();++i)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[i]==dp[j]+1)
                    {
                        cnt[i]+=cnt[j];
                    }
                    if(1+dp[j]>dp[i])
                    {
                        cnt[i]=cnt[j];
                        dp[i] = 1+dp[j];
                        maxi =max(maxi,dp[i]);
                    }
            
                }
            }    
       }
        int res =0;
        for(int i =0;i<nums.size();i++)
        {
            if(dp[i] == maxi)
                res += cnt[i];
        }
        return res;
    }
        
};