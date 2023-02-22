class Solution {
public:
    int maxCount(vector<int>& b, int n, int msum) {
        int mp[10001]={};
        for(auto it:b)
            mp[it]=1;
        int cnt=0;
        
        for(int i=1;i<=n;i++)
        {
            if(mp[i]==0 && (msum-i>=0))
                cnt++,msum-=i;
        }
        return cnt;
        
    }
};