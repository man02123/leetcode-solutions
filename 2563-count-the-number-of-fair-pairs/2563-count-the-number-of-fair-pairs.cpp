class Solution {
public:
    long long countFairPairs(vector<int>& nums, int l, int u) {
        
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int x=lower_bound(nums.begin()+i+1,nums.end(),l-nums[i])-nums.begin();
            int y=upper_bound(nums.begin()+i+1,nums.end(),u-nums[i])-nums.begin()-1;
            if(x<=y)
            ans+=y-x+1;
        }
        return ans;
        
    }
};