class Solution {
public:long long res;
    long long maxStrength(vector<int>& nums) {
        res=LONG_MIN;
        solve(nums,0,1,0);
        return res;
        
    }
    void solve(vector<int>& nums , int ind ,long long prd ,int tcount)
    {
        
        if(ind>=nums.size() && tcount>0)
        {
            res = max(prd,res);
            return ;
        }
        if(ind>=nums.size())
            return;
      
        
           if(nums[ind]!=0)
           {
            solve(nums,ind+1,prd*nums[ind],tcount+1);
            solve(nums,ind+1,prd,tcount);
           }
          else
          {
            solve(nums,ind+1,0,tcount+1);
            solve(nums,ind+1,prd,tcount);
          }
            
     
        
       //return max(take,ntake); 
        
    }
};