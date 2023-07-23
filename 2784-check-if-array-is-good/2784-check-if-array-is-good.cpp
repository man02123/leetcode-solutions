class Solution {
public:
    bool isGood(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());
        
        for(auto it:nums)
            mp[it]++;
        
        if(mp[nums.back()] != 2)return false;
        
        bool ans = true;
        
        for(int i = 0;i<nums.size();i++){
            
            
            if(i!= nums.size()-1  && nums[i]!=i+1)
                return false;
            
        }
        return true;
        
    }
};