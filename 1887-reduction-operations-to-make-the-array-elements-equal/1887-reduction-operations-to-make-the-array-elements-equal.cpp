class Solution {
public:
    int reductionOperations(vector<int>& nums) {
       
        
        sort(nums.begin(),nums.end());
        
       int ans = 0;
        int cfre = 0;
        
        for(int i=1;i<nums.size();i++){
            
            if(nums[i] != nums[i-1])cfre++;
            
            ans += cfre;
        }
            
        
        return ans;
    }
};