class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int it=0;it<strs.size();++it)
        {
            string x=strs[it];
         sort(x.begin(),x.end());
            
             mp[x].push_back(strs[it]);
        
        
        }
        vector<vector<string>> s;
    for(auto it=mp.begin();it!=mp.end();++it)
    {
        s.push_back(it->second);
    }
        return s;
    }
};