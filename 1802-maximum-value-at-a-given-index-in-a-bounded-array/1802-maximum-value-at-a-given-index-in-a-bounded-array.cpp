#define ll long long 
class Solution {
public:int maxelem;
    int maxValue(int n, int ind, int maxi) {
        int l  = 1, r=maxi;
        maxelem = n;
        ll ans = 1;
        while(r-l>=0)
        {
            ll mid = (l+r)/2;
            
            if(check(mid,ind,maxi) == true)
            {
                ans = max(ans,mid);
                l = mid+1;
            }
            else
                r= mid-1;
        }
        return ans;
        
    }
    bool check(int mid ,int ind , int maxi){
       
        ll sum = 0;
        
        ll lsum = 0,rsum = 0;
        ll lrem=ind ,rrem=maxelem -ind-1;
        
        ll m = mid-1;
        
        if(rrem<=m)
        {
            rsum = m*(m+1)/2 - (m-rrem+1)*(m-rrem)/2;
        }
        else{
            rsum =(m*(m+1))/2 + rrem-m;
        }
        
        if(lrem<=m){
            lsum = (m*(m+1))/2 - ((m-lrem+1)*(m-lrem))/2;
        }
        else{
           lsum =(m*(m+1))/2 + lrem-m; 
        }
        
        sum = lsum+rsum+mid;
            
        if(sum<=maxi)
        return true;
        
        return false;
    }
};