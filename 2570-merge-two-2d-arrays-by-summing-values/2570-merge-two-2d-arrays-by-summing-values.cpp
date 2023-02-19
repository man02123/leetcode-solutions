class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1, vector<vector<int>>& n2) {
       map<int,int> mp;
        
        for(auto it:n1)  
            mp[it[0]]=it[1];
        
         for(auto it:n2)
         {
             if(mp.find(it[0])!=mp.end())
             mp[it[0]]+=it[1];
            else
            mp[it[0]]=it[1];
             
         }
            
        
        vector<vector<int>> res;
        for(auto it:mp)
        {
            vector<int> temp;
            temp.push_back(it.first);
            temp.push_back(it.second);
            res.push_back(temp);
        }
        return res;
        
    }
};