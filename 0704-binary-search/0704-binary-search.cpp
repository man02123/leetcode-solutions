class Solution {
public:
    int search(vector<int>& nums, int t) {
        int  l =0 ,r= nums.size();
        
        while(r-l>0){
            int mid = (l+r)/2;
            if(nums[mid] == t)
                return mid;
            else if(nums[mid]<t)
                l = mid+1;
            else
                r = mid;
        }
        return -1;
        
    }
};