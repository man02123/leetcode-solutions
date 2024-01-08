
class Solution {
public:
   
    int numberOfArithmeticSlices(vector<int>& nums) {
       
        int ans = 0;
        int n = nums.size();
  
         map<tuple<long,int,int>,int> mp;
        for(int i =0;i<n;i++){
            for(int j = i+1 ;j<n;j++){
                
                long diff = (long)nums[j]-(long)nums[i];
                ans += solve(nums,j+1,j,diff,mp);
            }
        }
        return ans;
    }
    int solve(vector<int>& nums , int curr  , int prev,long diff,map<tuple<long,int,int>,int>& mp){
        
      if(curr >=nums.size()  || diff <INT_MIN || diff>INT_MAX){
          return 0;
      }
        if(mp.find({diff,curr,prev}) != mp.end())return mp[{diff,curr,prev}];
        
        int ans = 0;
        for(int i = curr;i<nums.size();i++){
            if((long)nums[i]-(long)nums[prev] == diff){
               ans += 1+solve(nums, i+1,i,diff,mp); 
            }
        }
       return mp[{diff,curr,prev}] = 
           ans; 
        
    }
};