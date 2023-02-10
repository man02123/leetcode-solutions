class Solution {
public:
    int equalPairs(vector<vector<int>>& g) {
    map<vector<int>,int> mp;
        for(int j=0;j<g[0].size();j++)
        {
            vector<int> tmp;
            for(int i=0;i<g.size();i++)
            {
                tmp.push_back(g[i][j]);
            }
            mp[tmp]++;
        }
        
        int res=0;
         for(int i=0;i<g.size();i++)
        {
             if(mp.find(g[i])!=mp.end())
                 res+=mp[g[i]];
            
        }
        
        
        
        return res;
    }
};