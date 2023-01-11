class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1;
        int res=INT_MIN;
        int max2=INT_MIN;
        for(auto i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            { prod=prod*nums[i];
            max2=max(max2,max(prod,nums[i]));
            }
            else
            {
                res=max(res,0);
                prod=1;
            }
        }
        prod=1;
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]!=0)
            { prod=prod*nums[i];
            max2=max(max2,max(prod,nums[i]));
            }
            else
            {
                res=max(res,0);
                prod=1;
            }
        }
          return max(max2,res);  
        
    }
};