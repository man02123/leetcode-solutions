class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int lind = -1;
        int rind = -1;
        
        int l =0 ,r = nums.size()-1;
        
        while(l<=r){
            int mid = (l)+(r-l)/2;
            
            if(nums[mid] == t){
                lind = mid;
                r = mid-1;
            }
            else if(nums[mid] < t){
                l =  mid+1;
            }
            else
                r = mid-1;
        }
        
        l = 0 , r = nums.size()-1;
         while(l<=r){
            int mid = (l)+(r-l)/2;
            
            if(nums[mid] == t){
                rind = mid;
                l = mid+1;
            }
            else if(nums[mid] < t){
                l =  mid+1;
            }
            else
                r = mid-1;
        }
        
        return {lind,rind};
    }
};