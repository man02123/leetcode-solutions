class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        
        for(int i =0;i<=nums.size()-3;i++)
        {
            
            
            while(i>0 && nums[i] == nums[i-1] && i<=nums.size()-3)
                i++;
            
            int l =i+1,r = nums.size()-1;
            
            while(l<r)
            {
               if(nums[i] +nums[l]+nums[r] ==0)
               {
                res.push_back({nums[i] ,nums[l],nums[r]});
                    
                   while(l<r && nums[l]==nums[l+1])
                    l++;
                   
                    while(r>l && nums[r] == nums[r-1])
                    r--;
                   
                   l++;
                   r--;
               }
                else if(nums[l]+nums[r]+nums[i]<0)
                    l++;
                else
                    r--;
                
            }
            
            
        }
        return res;
        
    }
};