class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        
        int ans = 0;
        
        unordered_map<int ,int> mp;
        
        int left = 0;
        int maxfreq = 0;
        
        for(int r = 0;r<n;r++){
            
            mp[nums[r]]++;
            maxfreq = max(maxfreq , mp[nums[r]]);
            int len = r-left+1;
            
            if( len -maxfreq <= k )
                ans = max(ans , maxfreq);
            else
            {
                mp[nums[left]]--;
                maxfreq = max(maxfreq , mp[nums[left]]);
                left++;
            }
            
        }
        return ans;
        
    }
};