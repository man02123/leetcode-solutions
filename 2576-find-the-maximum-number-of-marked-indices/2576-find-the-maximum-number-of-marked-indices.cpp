#define ll long long
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
       
        sort(nums.begin(),nums.end());
        
        multiset<ll> mul1,mul2;
        int n = nums.size();
        
        for(int i  =0;i<(n/2);i++)
         mul1.insert(nums[i]);
        
        for(int i  =n/2;i<n;i++)
         mul2.insert(nums[i]);
        
        int ans = 0;
        
        for(auto it=mul1.begin() ; it!=mul1.end();it++)
        {
            ll num = *it;
            
            ll to_find = (2*num);
            
            auto pos = mul2.lower_bound(to_find);
            if(pos == mul2.end())
                continue;
            else
            {
                ans+=2;
                mul2.erase(pos);
            }
            
        }
        
        return ans;
    }
};