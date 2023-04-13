class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        int sum=0;
        mp[sum]++;
        int res=0;
        for(auto it:nums)
        {
            sum+=it;
            if(mp[sum-goal]>0)
                res+=mp[sum-goal];
            
            mp[sum]++;
        }
        return res;
    }
};