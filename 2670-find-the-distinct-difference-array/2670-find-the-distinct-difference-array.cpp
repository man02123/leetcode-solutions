class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> res;
        set<int> st1;
        for(int i=0;i<nums.size();i++)
        {
            set<int> temp;
            st1.insert(nums[i]);
            for(int j = i+1 ;j<nums.size();j++)
            {
                temp.insert(nums[j]);
            }
            res.push_back(st1.size()-temp.size());
        }
        return res;
        
    }
};