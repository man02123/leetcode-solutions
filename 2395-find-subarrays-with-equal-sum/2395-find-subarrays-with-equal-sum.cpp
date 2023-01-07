class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        if(nums.size()<=2)return false;
        unordered_map<int,int> mp;
        int sum=0;
        for(int i=1;i<nums.size();i++)
        {
            if(mp[nums[i]+nums[i-1]]>0)return true;
            
            mp[nums[i]+nums[i-1]]++;
        }
        return false;
    }
        
    };
 