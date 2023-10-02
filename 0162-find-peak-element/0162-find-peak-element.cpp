class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0 ,r = nums.size()-1;
        if(n-2>=0 && nums[n-1] > nums[n-2])
            return n-1;
        if(n-2>=0 && nums[1]<nums[0])
            return 0;
        
        
        while(l<r){
            int mid = (l+r)/2;
            
            if( mid-1>=0 &&  mid+1<n && nums[mid] > nums[mid-1] && nums[mid+1]<nums[mid] )
                return mid;
            else if(mid-1>=0 && nums[mid] > nums[mid-1] )
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};