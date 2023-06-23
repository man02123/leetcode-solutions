class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
       vector<unordered_map<int,int>> dp(nums.size());
        int res= 1;
        for(int i =1;i<nums.size();i++){
            for(int j=0 ;j<i;j++){
                
                int diff = nums[i]-nums[j];
                
                if(dp[j].count(diff)>0)
                {
                    dp[i][diff] =1+dp[j][diff];
                }
                else
                    dp[i][diff] = 2;
              res = max(res,dp[i][diff]) ;    
            }
            
        }
        return res;
        
        
        
    }
};