class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=0,r=INT_MAX;
        int res=INT_MAX;
        
        int mid;
        while(l<r)
        {
            mid=(l)+(r-l)/2;
            
            if(check(nums,mid,k)==true)
            {
                res=min(res,mid);
                r=mid;
            }
           else
               l=mid+1;   
        }
        return res;
        
    }
    bool check(vector<int>& nums,int mid,int sub)
    {
        int sum=0;
        int part=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>mid)
                return false;
            
            
            if(sum+nums[i]<=mid)
            {
                sum+=nums[i];  
            }
            else
            {
                part++;
                sum=nums[i];
            }  
        }
        part++;
        return (part<=sub);
        
    }
};