class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nz = 0,z = 0;
        int n = nums.size();
        
        while(nz<nums.size() && z<nums.size())
        {
            while(nz<n && nums[nz]==0)
                nz++;
            while(z<n && z<nz && nums[z]!=0)
                z++;
            
            if(nz<n && z<n)
                swap(nums[nz++],nums[z++]);
      
        }
        
    }
};