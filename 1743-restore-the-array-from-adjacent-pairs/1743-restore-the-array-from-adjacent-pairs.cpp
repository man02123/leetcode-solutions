class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ad) {
        unordered_map<int , vector<int>> mp;
        unordered_map<int,bool> vis;
        int start;
        for(auto it:ad){
    
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
            vis[it[0]] = 0;
            vis[it[1]] = 0;
        } 
       vector<int> t;
        
        for(auto it:mp)
            if(it.second.size() == 1)start = it.first;
                
          solve(mp, t ,vis,start);  
        //}
       
       return t; 
    }
   void solve(unordered_map<int , vector<int>> &mp ,vector<int> &t,unordered_map<int,bool> &vis,int node)
   {
       
       if(vis[node] == 1)return;
       
       vis[node] = 1;
       t.push_back(node);
       
        vector<int> temp = mp[node];
        
       for(auto it:temp)
           solve(mp,t,vis,it);
   }
       
};