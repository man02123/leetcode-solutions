class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int res=nums[0];
        int sum=nums[0];
        int maxsofar=nums[0];
        int maxtotal=nums[0];
        
        int minsofar=nums[0];
        int mintotal=nums[0];
    
        
        for(int i=1;i<nums.size();i++)
        {
            maxsofar=max(maxsofar+nums[i],nums[i]);
            maxtotal=max(maxsofar,maxtotal);
            
            minsofar=min(minsofar+nums[i],nums[i]);
             mintotal=min(minsofar,mintotal);
            sum+=nums[i];
        }
        
        if(mintotal==sum) return maxtotal;
        
       return max(sum-mintotal,maxtotal); 
    }
};