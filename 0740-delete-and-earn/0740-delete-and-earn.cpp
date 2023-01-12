class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mxelem=*max_element(nums.begin(),nums.end());
        
        vector<int> mp(mxelem+1,0);
        for(auto it:nums)mp[it]+=it;
        
        for(int j=2;j<mp.size();j++)
            mp[j]=max(mp[j-1],mp[j-2]+mp[j]);

        
        return *max_element(mp.begin(),mp.end());
        
    }
};