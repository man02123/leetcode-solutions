class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& nums) {
        
        int ans = INT_MAX;
        
        int start = 0,end = 0;
        int currsum = 0;
        
        
        for(int end= 0;end<nums.size() ; end++)
        {
            currsum+=nums[end];
            
            if(currsum-tar>=0)
            {
                ans = min(end-start+1,ans);
            }
            while(currsum-tar>= 0)
            {
                currsum-=nums[start];
                start++;
                
                if(currsum-tar>=0)
                ans = min(end-start+1,ans);
                
            }
        }
        return ans ==INT_MAX ?0:ans;
        
    }
};