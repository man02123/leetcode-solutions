class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prd = 1, maxi1=INT_MIN, maxi2=INT_MIN;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                prd= prd*nums[i];
                maxi1 = max(maxi1,prd);
            }
            else
            {
                maxi1 = max(maxi1,0);
                prd = 1;
            }
        }
        prd = 1;
        for(int i = nums.size()-1;i>=0;i--)
        {
            if(nums[i]!=0)
            {
                prd= prd*nums[i];
                maxi2 = max(maxi2,prd);
            }
            else
            {
                maxi1 = max(maxi1,0);
                prd = 1;
            }
        }
        return max(maxi1,maxi2);
        
    }
};