class Solution {
public:
    int minimumCardPickup(vector<int>& c) {
        unordered_map<int,int> mp;
        
        int res=INT_MAX;
        int j=0;
        
        for(int i=0;i<c.size();i++)
        {
           if(mp.find(c[i])!=mp.end())
               res=min(res,i-mp[c[i]]+1);
            
            mp[c[i]]=i;
        }
        return (res==INT_MAX)?-1:res;
        
    }
};