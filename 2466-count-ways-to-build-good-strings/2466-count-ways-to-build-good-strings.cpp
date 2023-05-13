class Solution {
public:int dp[100005];
    #define mod 1000000007
    int countGoodStrings(int l, int h, int z, int o) {
        memset(dp,-1,sizeof(dp));
        return recur(l,h,z,o,0);
    }
    
    int recur(int l,int h,int z, int o,int slen)
    {
        if(slen>h)
            return 0;
        if(dp[slen]!=-1)
            return dp[slen];
        
        int cnt = 0;
        
        if(slen+z<=h)
        {
            if(slen+z>=l && slen+z<=h)
                cnt++;
            
          cnt +=(recur(l,h,z,o,slen+z)%mod);
        }
        if(slen+o<=h)
        {
            if(slen+o>=l && slen+o<=h)
                cnt++;
          cnt +=recur(l,h,z,o,slen+o)%mod;
        }
        return dp[slen]  = cnt%mod;
    }
};