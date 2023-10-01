class Solution {
public:
    int search(vector<int>& nums, int t) {
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
        
        
        if(ind !=-1 && t >= nums[ind] && t<= nums.back()){
            l = ind,r = nums.size()-1;
            while(l<=r){
                int mid = (l)+(r-l)/2;
            
            if(nums[mid] == t){
                return mid;
            }
            else if(nums[mid] < t)
                l = mid+1;
                else
                    r = mid-1;
                
            }
            return -1;
        }
        else if(ind!=-1){
            l = 0,r = ind-1;
            while(l<=r){
                int mid = (l)+(r-l)/2;
            
            if(nums[mid] == t){
                return mid;
            }
            else if(nums[mid] < t)
                l = mid+1;
                else
                    r = mid-1;
                
            }
            return -1;
            
        }
        else{
            l = 0,r = nums.size()-1;
            while(l<=r){
                int mid = (l)+(r-l)/2;
            
            if(nums[mid] == t){
                return mid;
            }
            else if(nums[mid] < t)
                l = mid+1;
                else
                    r = mid-1;
                
            }
            return -1;
            
            
        }
        
        
        return -1;
        
    }
};