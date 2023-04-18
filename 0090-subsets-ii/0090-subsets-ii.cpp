class Solution {
public:vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        recur(nums,0,temp);
        return res;
    }
    void recur(vector<int>& nums,int ind,vector<int>& temp)
    {
        res.push_back(temp);
        
        
        for(int i=ind;i<nums.size();i++)
        {
            if(i>ind && nums[i]==nums[i-1])
                continue;
            temp.push_back(nums[i]);
            recur(nums,i+1,temp);
            temp.pop_back();
            // recur(nums,i+1,temp);
        }
        
    }
};