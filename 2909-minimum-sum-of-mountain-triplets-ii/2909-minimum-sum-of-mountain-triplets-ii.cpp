class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> lmin(n,INT_MAX) ,rmin(n,INT_MAX);
        
        int lm = INT_MAX;
        for(int i =0;i<n;i++){
          lm = min(lm,nums[i]);
            lmin[i] = lm;  
        }
        int rm = INT_MAX;
        for(int i =n-1;i>=0;i--){
          rm = min(rm,nums[i]);
            rmin[i] = rm;  
        }
        int ans = INT_MAX;
        for(int i =0;i<n;i++){
            if(lmin[i] < nums[i] && rmin[i]<nums[i]){
                ans = min(ans, nums[i]+lmin[i]+rmin[i]);
            }
            
        }
        return (ans == INT_MAX) ? -1:ans;
        
    }
};