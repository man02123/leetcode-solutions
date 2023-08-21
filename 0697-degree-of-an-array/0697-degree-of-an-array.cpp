class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        
        int mx = 0;
        for(auto it:mp)
            mx = max(mx , it.second);
        
        
        int l = 0;
        int ans = INT_MAX;
        mp.clear();
        int cf = 0;
        int elem = -1;
        
        for(int r = 0;r<nums.size();r++){
            
            mp[nums[r]]++;
            cf = max(cf, mp[nums[r]]);
            
            if(cf == mx)
                elem = nums[r];
                
            
            if(cf == mx)
            {
                ans = min(ans ,r-l+1);
                while(cf == mx && l<r)
                {
                    mp[nums[l]]--;
                    
                    if(nums[l]==elem)
                        cf--;
                    
                    l++;
                     
                    if(cf == mx)
                     ans = min(ans  , r-l+1);
                      
                }

            }
                
            
        }
        return ans;
        
    }
};