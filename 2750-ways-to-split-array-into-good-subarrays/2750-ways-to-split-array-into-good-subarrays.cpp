class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
       
        
        int i=0;
        int n = nums.size();
        
        while(i<n && nums[i]==0)
            i++;
        
        if(i==n)
            return 0;
        long long ans = 1;
        
        long long cnt= 0;
        for(i;i<n;i++)
        {
            if(nums[i]==0)
            {
                cnt++;
                
            }
            else
            {
                long long t=ans*cnt;
                t=t%1000000007;
                ans+=t;
                cnt=0;
            }
                
        }
        return ans%1000000007;
    }
};