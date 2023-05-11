class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        
        for(int i=1;i<=nums1.size();i++)
        {
            for(int j = 1;j<=nums2.size();j++)
            {
                if(nums1[i-1] == nums2[j-1])
                {
                    int x = 1+dp[i-1][j-1];
                    int y =dp[i-1][j];
                    int z =dp[i][j-1];
                    dp[i][j] = max({x,y,z});
                }
                else
                {
                     int y =dp[i-1][j];
                    int z =dp[i][j-1];
                    dp[i][j] = max({y,z});   
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
        
        
    }
};