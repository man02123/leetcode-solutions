class Solution {
public:
    int dp[15][1<<15];
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        memset(dp,-1,sizeof(dp));
        int mask = 0;
        
        return solve(nums1 , nums2 , 0 , mask);
    }
    int solve(vector<int>& nums1 , vector<int>& nums2 ,int ind , int mask)
    {
        
        if(ind>=nums1.size())return 0 ;
        if(dp[ind][mask]!=-1)
            return dp[ind][mask];
        
        int ans = INT_MAX;
        
        for(int j = 0 ; j < nums1.size();j++)
        {
            if( mask&(1<<j))
            {
                continue;
            }
                int new_mask = mask|(1<<j);
                int val = nums2[j]^nums1[ind];
            
              ans = min(ans , solve(nums1,nums2,ind+1,new_mask)+val);
                   
        }
        
        return dp[ind][mask] = ans;
        
        
    }
    
};