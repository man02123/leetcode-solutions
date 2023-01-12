class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(size(nums)<=1)return 1;
        
        int res=1;
        int len=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                len++;
                res=max(res,len);
            }
            else
                len=1;        
        }
        return res;
        
    }
};