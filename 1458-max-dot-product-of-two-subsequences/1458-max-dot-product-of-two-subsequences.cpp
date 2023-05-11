class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
         vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        for(int i=1;i<=nums2.size();i++)
            dp[0][i] = -1000*500;
       // dp[0][0] = nums1[0]*nums2[0];
        
         for(int i=1;i<=nums1.size();i++)
            dp[i][0] = -1000*500; 
        
        for(int i=1;i<=nums1.size();i++)
        {
            for(int j = 1;j<=nums2.size();j++)
            {
               
                    int x =nums1[i-1]*nums2[j-1]+max( dp[i-1][j-1],0);
                    int y =dp[i-1][j];
                    int z =dp[i][j-1];
                  
                   dp[i][j] = max({x,y,z});
               
            }
        }
        return dp[nums1.size()][nums2.size()];
        
    }
};