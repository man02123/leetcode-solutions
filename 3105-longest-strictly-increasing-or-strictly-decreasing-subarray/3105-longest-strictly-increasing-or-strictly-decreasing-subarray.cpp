class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;
        
        for(int i =0;i<n;i++){
            for(int j =i;j<n;j++){
                bool inc = 0,dec = 0;
                
                for(int k =i+1;k<=j;k++){
                    
                    if(nums[k] <= nums[k-1]){
                        inc = 1;
                    }
                     if(nums[k] >= nums[k-1]){
                        dec = 1;
                    }
                    
                }
                if(!inc ||  !dec)ans = max(ans , j-i+1);
            }
        }
        return ans;
    }
};
