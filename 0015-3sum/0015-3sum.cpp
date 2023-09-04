class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        
        vector<vector<int>> ans;
        
        for(int i = 0;i<nums.size();i++){
            while(i>0 && nums[i] == nums[i-1] && i<=nums.size()-3)
                i++;
            int num = nums[i];
            int l = i+1;
            int r = n-1;
            long long csum = num;
            while(l<r){
                csum  = num + nums[l]+nums[r];
                
                if(csum == 0){
                    ans.push_back({num,nums[l],nums[r]});
               
                while(l<r && nums[l+1] == nums[l] )
                    l++;
                
                while(l<r && nums[r-1] == nums[r])
                    r--;
                    
                  r--;
                }
                
                else if(csum<0)
                l++;
                else r--;
                
                    
                    
            }
        }
        return ans;
    }
};