class Solution {
public:int ans ;
    int distributeCookies(vector<int>& cook, int k) {
        ans =INT_MAX;
        
        vector<int> v(k,0);
        solve(cook ,v ,0);
        
        return ans;
    }
    void solve(vector<int>& cook , vector<int> &v,int ind)
    {
        if(ind>=cook.size())
        {
            int mx = *max_element(v.begin(),v.end());
            ans = min(mx,ans);
            return;
        }
        
        for(int i =0;i<v.size();i++)
        {
            v[i]+=cook[ind];
            solve(cook,v,ind+1);
            v[i]-=cook[ind];
        }
        
    }
};