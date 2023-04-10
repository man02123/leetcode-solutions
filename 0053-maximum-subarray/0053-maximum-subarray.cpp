class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=nums[0];
        int maxsum=nums[0];
        if(nums.size()<=1)
            return nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(currsum+nums[i]>=nums[i])
            {
                currsum+=nums[i];
                maxsum=max(maxsum,currsum);
            }
            else
            {
                currsum=nums[i];
                maxsum=max(maxsum,currsum);
            }
        }
        return maxsum;
        
    }
};