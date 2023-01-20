class Solution {
public:set<vector<int>> mp;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
     vector<int> v;
        int ind=-1;
        solve(nums,0,v);
        
        return vector<vector<int>>{mp.begin(),mp.end()};
    }
    void solve(vector<int>& nums,int ind,vector<int>&temp)
    {
        
        if(ind>=nums.size())
        {
            if(temp.size()>1)
                mp.insert(temp);
            return;
        }
        
       if(temp.size()==0 || temp.back()<=nums[ind])
       {
           temp.push_back(nums[ind]);
           solve(nums,ind+1,temp);
           temp.pop_back();
           solve(nums,ind+1,temp);
       }
        else
        solve(nums,ind+1,temp);
   
    }
};