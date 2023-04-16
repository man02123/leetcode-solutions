class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& d) {
     
        int res=0;
        int ans=INT_MAX;
        for(auto it:d)
        {
            int cnt=0;
            for(auto it2:nums)
            {
                if(it!=0 && it2%it==0)
                    cnt++;
            }
            if(res<cnt)
            {
                res=cnt;
                ans=it;
            }
            else if(res==cnt)
                ans=min(ans,it);
        }
        return ans;
    }
};