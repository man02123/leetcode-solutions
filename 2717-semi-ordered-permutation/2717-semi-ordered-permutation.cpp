class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int lar=-1,s=-1;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==nums.size())
                lar=i;
            
            if(nums[i]==1)
                s=i;   
        }
        
        int dist= s+((nums.size()-1)-lar);
        
        if(lar<s)
            dist--;
        return dist;
        
    }
};