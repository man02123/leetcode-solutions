class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int ans = 0;
        
        int l = 0;
        int sum = 0;
        
        for(int r = 0;r<nums.size();r++){
            
            sum += nums[r];
            int len = r-l+1;
            
            if(len-sum <= k){
                ans = max(ans , len);
            }
            else
            {
                while(l < r && (r-l+1)-sum >k )
                {
                    sum -= nums[l];
                    l++;
                }

            }
            
        }
        return ans;
        
    }
};