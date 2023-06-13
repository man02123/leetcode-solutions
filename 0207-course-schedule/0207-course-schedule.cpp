class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pr) {
        vector<int> g[n];
        vector<int> indeg(n);
        
        for(auto it:pr){
            g[it[1]].push_back(it[0]);
            indeg[it[0]]++; 
        }
        queue<int> q;
        for(auto i = 0;i<n;i++)
            if(indeg[i] == 0)
                q.push(i);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it:g[node]){
                indeg[it]--;
                
                if(indeg[it]==0)
                    q.push(it);
            }
            
        }
        for(auto it:indeg)
            if(it!=0)return false;
        
        return true;
        
    }
};