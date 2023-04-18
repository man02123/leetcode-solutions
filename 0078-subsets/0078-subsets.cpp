class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> res;
        vector<int> temp;
       return recur(nums,0,res,temp);
        
        
    }
   vector<vector<int>> recur(vector<int>& nums,int ind,vector<vector<int>> &res,vector<int>&temp)
   {
       
       if(ind==nums.size())
       {
           res.push_back(temp);
           return res;
       }
       temp.push_back(nums[ind]);
       recur(nums,ind+1,res,temp);
       temp.pop_back();
       recur(nums,ind+1,res,temp);
       return res;
   }
};