class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int g) {
        
        unordered_map<int ,int> mp;
        int csum = 0;
        mp[0]++;
        int ans = 0;
        
        for(int i = 0;i<nums.size();i++){
            csum += nums[i];
            if(mp.find(csum-g) != mp.end()){
                ans += mp[csum-g];
            }
            mp[csum]++;
        }
        return ans;
    }
};