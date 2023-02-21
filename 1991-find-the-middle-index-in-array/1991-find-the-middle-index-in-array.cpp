class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        int sum=0;
        for(auto it:nums)
            sum+=it;
        
        int rsum=0;
        
        for(int i=0;i<nums.size();i++)
        {
           
            sum-=nums[i];
            if(rsum==sum)
                return i;
             rsum+=nums[i];
        }
        
        return -1;
        
    }
};