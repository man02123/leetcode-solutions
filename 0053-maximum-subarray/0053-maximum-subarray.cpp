class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        
        int l = 0;
        int csum = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            if(csum+nums[i]>=nums[i])
            {
                csum +=nums[i];  
            }
            else
                csum = nums[i]; 
            
            sum = max(csum,sum);
            
        }
        return sum;
        
    }
};