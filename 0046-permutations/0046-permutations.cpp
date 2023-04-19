class Solution {
public:vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
    vector<int> temp;
        backtrack(nums,0);
    return res;
        
    }
    void backtrack(vector<int> &nums,int ind)
    {
        if(ind==nums.size()-1)
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++)
        {
            vector<int> v=nums;
            swap(v[ind],v[i]);
            backtrack(v,ind+1);
        }
    }
};