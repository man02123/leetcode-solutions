class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        unordered_map<int,int> mp;
        map<int,vector<int>> mp2;
        
        for(auto it:t)
            mp2[it[0]]=it;
        
        for(int i=1;i<=n;i++)
            mp[i]=0;
        
        for(auto it:t)
            mp[it[1]]++;
        int res=-1;
        
        for(auto it:mp)
        {
            if(mp[it.first]==n-1 && mp2.find(it.first)==mp2.end())
                res=it.first;
        }
        
        
       return res; 
    }
};