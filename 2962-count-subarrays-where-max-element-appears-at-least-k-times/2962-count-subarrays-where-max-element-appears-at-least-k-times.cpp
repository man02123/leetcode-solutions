class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int mx = *max_element(begin(nums),end(nums));
        
        int st = 0;int fmax = 0;
        int cmax = 0;
        
        for(int r = 0;r<n;r++){
                
                if(nums[r] == mx)fmax++;
                
                if(fmax == k){
                    
                    while(fmax == k){
                    ans+=(n-r);
                        
                    if(nums[st] == mx)
                        fmax--;   
                    
                st++;
                }
                  
                }          
        }
        return ans;
    }
};