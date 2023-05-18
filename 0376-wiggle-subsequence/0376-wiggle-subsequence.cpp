class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        //vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,1));
        int peak  =1,val = 1;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
                peak = val+1;
            else if(nums[i]<nums[i-1])
                val =peak+1;
        }
        return max(peak,val);
    }
};