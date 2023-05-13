class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        unordered_map<int,int> mp;
        
        for(auto it:e)
        {
          mp[it[0]]++;
          mp[it[1]]++;  
            
        }
        for(auto it:mp)
        {
            if(it.second == e.size())
                return it.first;
        }
        return -1;
    }
};