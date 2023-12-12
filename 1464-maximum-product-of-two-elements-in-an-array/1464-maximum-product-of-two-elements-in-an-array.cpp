class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(begin(nums),end(nums));
        
        return (nums[nums.size()-2]-1)*(nums.back()-1);
    }
};