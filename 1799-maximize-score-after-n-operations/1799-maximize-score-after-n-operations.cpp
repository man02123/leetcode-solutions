class Solution {
public:
    int dp[15][1<<15];
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int mask = (1<<n)-1;
        memset(dp,-1,sizeof(dp));
        
        return solve(nums , mask,1);
        
    }
    int solve(vector<int> &nums, int mask,int ind )
    {
        
        if(mask == 0)
            return 0;
        if(dp[ind][mask]!=-1)
            return dp[ind][mask];
        
        int res= 0;
        for(int i =0;i<nums.size();i++)
        {
        if(mask & (1<<i))
        {
            int new_mask = mask ^ (1<<i);
            for(int j = 0; j<nums.size() ;j++)
            {
                if(j!=i && (mask & (1<<j)))
                {
               res =max(res,ind * __gcd(nums[i],nums[j]) +                     solve(nums,new_mask^(1<<j),ind+1));
                }
            }
        }
        }
     return dp[ind][mask] = res;   
        
    }
};