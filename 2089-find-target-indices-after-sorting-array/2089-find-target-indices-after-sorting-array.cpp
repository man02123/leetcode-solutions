class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        int x=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        while(x<nums.size() && nums[x]==target)
            res.push_back(x),x++;
        
        return res;
        
    }
};