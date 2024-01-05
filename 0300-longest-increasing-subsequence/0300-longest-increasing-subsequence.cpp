class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
  
     vector<int> res{nums[0]};
        for(int i=1;i<n;i++)
        {
         int ind=(lower_bound(res.begin(),res.end(),nums[i])-res.begin());
            
            if(ind>=res.size())
                res.push_back(nums[i]);
            else
                res[ind]=nums[i];
        }
        return res.size();
    }
};