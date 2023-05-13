class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        
        int sc = 0;
        for(int i=0;i<nums.size();i++)
        {
            sort(nums[i].begin(),nums[i].end());   
            
        }
        for(int j =nums[0].size()-1;j>=0;j--)
        {
            int maxi = 0;
            for(int i=0;i<nums.size();i++)
            {
                maxi =max(maxi,nums[i][j]);
            }
            sc+=maxi;
        }
        return sc;
        
    }
};