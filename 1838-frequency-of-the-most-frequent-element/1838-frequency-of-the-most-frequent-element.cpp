#define ll long long int
class Solution {
public:vector<ll> pre;int op;int x;
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        op = k;
        x = nums[0];
        ll s =  0;
        pre.push_back(0);
        for(auto it:nums){
          s+=it;
            pre.push_back(s);
        }
        int ans = 1;
        for(int i =0;i<nums.size();i++){
            ans = max(ans,1+bs(0,i,nums[i]));
        }
        return ans;
    }
    int bs(int lo , int hi,int elem){
        int tind = hi;
        
        ll ans = -1;
        while(lo<=hi){
            ll mid = (lo)+(hi-lo)/2;
            ll tsum = (elem*(tind-mid));
            //cout<<tsum;
            
            if( tsum-(pre[tind]-pre[mid]) <=op){
               ans = max(ans,tind-mid);
               hi = mid-1;
            }
            else{
                lo = mid+1;
            }
            
        }
        if(ans!=-1)return ans;
        return -5;
    }
};