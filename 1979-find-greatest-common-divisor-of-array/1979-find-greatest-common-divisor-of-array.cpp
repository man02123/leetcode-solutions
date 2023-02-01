class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx=0,mn=INT_MAX;
        for(auto it:nums)
        {
            mn=min(it,mn);
            mx=max(it,mx);
        }
        for(int i=mn;i>=2;i--)
            if(mx%i==0 && mn%i==0)return i;
        
        return 1;
    }
};