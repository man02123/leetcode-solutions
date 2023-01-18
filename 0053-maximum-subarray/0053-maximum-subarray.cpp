class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(sum+nums[i]<nums[i])
            {
                sum=nums[i];
                res=max(sum,res);
            }
            else
            {
                sum+=nums[i];
                res=max(res,sum);
            }
        }
        return res;
        
        
        
    }
};