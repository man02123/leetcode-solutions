class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> rsum(nums.size(),0);
        vector<int> lsum(nums.size(),0);
        
           int s1=0; 
        for(int i=1;i<nums.size();i++)
        {
            s1+=nums[i-1];
            rsum[i]=s1;
        }
        
        int s2=0;
        for(int j=nums.size()-2;j>=0;j--)
        {
            s2+=nums[j+1];
            lsum[j]=s2;    
        }
        for(int i=0;i<nums.size();i++)
            rsum[i]=abs(rsum[i]-lsum[i]);
        
        return rsum;
        
    }
};