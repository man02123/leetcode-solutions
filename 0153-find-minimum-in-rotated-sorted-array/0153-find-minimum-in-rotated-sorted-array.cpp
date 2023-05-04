class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int ans =INT_MAX;
        int  l = 0, r = nums.size()-1;
        
        while(l<r)
        {
            int mid = (l+r)>>1;
            
            if(nums[r]>nums[mid])
            {
                r = mid;
                ans = min({nums[mid],ans,nums[l]});
            }
            else
            {
                ans = min({ans,nums[r],nums[mid]});
                l = mid+1;
            }
        }
        return nums[l];
    }
};