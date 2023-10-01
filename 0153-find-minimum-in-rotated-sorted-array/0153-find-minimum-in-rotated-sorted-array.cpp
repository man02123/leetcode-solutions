class Solution {
public:
    int findMin(vector<int>& nums) {
         int ind = -1;
        
        int l = 0 , r = nums.size()-1;
        
        while(l<r){
            int mid = (l)+(r-l)/2;
            
            if(nums[mid] > nums[r]){
                ind = mid+1;
                l = mid+1;
            }
            else
                r = mid;
        }
        if(ind == -1)
            return nums[0];
        
        return nums[ind];
        
    }
};