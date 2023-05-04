class Solution {
public:
    bool search(vector<int>& nums, int tar) {
        int l =0,r=nums.size()-1;
        
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid] == tar)
                return true;
            
            while(nums[l]==nums[mid] && nums[mid] == nums[r] && l<r)
                l++,r--;
            
            if(nums[l]<=nums[mid])
            {
                if(nums[l]<=tar && nums[mid]>tar )
                    r=mid-1;
                else
                    l = mid+1;
            }
            else
            {
                if(nums[mid]<tar && nums[r]>=tar)
                    l= mid+1;
                else
                    r=mid-1;
            }
            
            
        }
        return false;
        
    }
};