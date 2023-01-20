class Solution {
public:set<vector<int>> res;
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        for(int i=0;i<nums.size()-1;i++)
        {
            helper(nums,temp,i);
        }
        
        
        
        // for(auto it:res)
        // temp2.push_back(it);
        
        return vector<vector<int>>{res.begin(),res.end()};
    }
    void helper(vector<int>& nums,vector<int>& temp,int ind)
    {
        if(ind>=nums.size())
        {
            if(temp.size()>1 )
            res.insert(temp);   
          return;  
        } 
        
        if(temp.size()>=2)
           res.insert(temp);
        
              
    if(temp.size()>0 && temp.back()<=nums[ind])
    {   
        temp.push_back(nums[ind]);
             helper(nums,temp,ind+1);
            temp.pop_back();
        helper(nums,temp,ind+1);
    }
    else if(temp.size()>0 && temp.back()>nums[ind])
    {
        vector<int> n;
        n.push_back(nums[ind]);
        helper(nums,n,ind+1);
        helper(nums,temp,ind+1);
    }
        else 
        { 
            temp.push_back(nums[ind]);
            helper(nums,temp,ind+1);
            temp.pop_back();
            helper(nums,temp,ind+1);
        }
    } 
};