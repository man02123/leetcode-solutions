class Solution {
public:
    string destCity(vector<vector<string>>& p) {
        
        unordered_map<string,int> mp;
        for(int i=0;i<p.size();i++)
          mp[p[i][0]]++;
        
        for(int i=0;i<p.size();i++)
        {
           if(mp[p[i][1]]==0)return p[i][1];
        }
        
        return "";
        
    }
};