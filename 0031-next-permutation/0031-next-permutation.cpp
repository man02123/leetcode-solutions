class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int bpoint = -1;
        for(int i =nums.size()-2;i>=0;i--)
        {
            if(nums[i+1]>nums[i])
            {
                bpoint = i;
                break;
            }
        }
        cout<<bpoint;
        
        if(bpoint == -1)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
        
        for(int i =nums.size()-1;i>=0;i--)
        {
            if(nums[i]>nums[bpoint])
            {
                swap(nums[i],nums[bpoint]);
                break;
            }
        }
        
        reverse(nums.begin()+bpoint+1,nums.end());
        
        
    }
};