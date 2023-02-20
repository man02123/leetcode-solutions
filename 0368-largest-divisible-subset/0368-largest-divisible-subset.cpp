class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n+1,0);
        vector<int> hash(n+1,0);
        int ind=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if((nums[i]%nums[j]==0 || nums[j]%nums[i]==0) && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(maxi<dp[i])
            {
            maxi=max(maxi,dp[i]);
              ind=i;  
            }
        }
        
        while(hash[ind]!=ind)
        {
            res.push_back(nums[ind]);
            ind=hash[ind];
        }
        res.push_back(nums[ind]);
        
         reverse(res.begin(),res.end());
         return res;
    }
};