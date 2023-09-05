class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int l = 0 , r = nums.size();
        
        while(l<r){
            
            int mid = (l+r)>>1;
            
            if(nums[mid] == t)return mid;
            
            else if(nums[mid] < t){
                l = mid+1;
            }
            else
                r = mid;
            
        }
        return r;
        
    }
};