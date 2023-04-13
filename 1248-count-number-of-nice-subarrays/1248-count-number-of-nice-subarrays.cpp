class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
          int res=0;
        int sum=0;
        unordered_map<int,int> mp;
        mp[sum]++;
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==1)
            sum++;
            
            if(mp.find(sum-k)!=mp.end())
                res+=mp[sum-k];
            
                mp[sum]++;   
        }
        return res;
        
    }
};