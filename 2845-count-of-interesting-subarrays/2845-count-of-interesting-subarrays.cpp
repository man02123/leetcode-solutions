class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        
        long long ans = 0;
        
        long long csum = 0;
        unordered_map<int,int> mp;
        mp[0]++;
        
        for(int i = 0;i<nums.size();i++){
           
            if(nums[i]%mod == k)
                csum++;
            
            long long temp = (csum-k) %mod; // if(csum-k) %mod is present => simplifing the equation cnt%mod == k to (csum-k)%mod
            
            if(mp.find(temp) != mp.end()){
                ans += mp[temp];
            }
            
            mp[csum%mod]++;  // as we need to work on remainder only so we store remainder only
               
        }
        
        
        return ans;
    }
};