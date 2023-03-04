class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
       vector<int> outdegree(g.size(),0);
        vector<vector<int>> newgraph(g.size());
        
        for(int i=0;i<g.size();i++)
            for(int j=0;j<g[i].size();j++)
                newgraph[g[i][j]].push_back(i);
        
       for(auto it:newgraph)
       {
           for(int i=0;i<it.size();i++)
               outdegree[it[i]]++;
       }
        
        
        queue<int> q;
        
        for(int i=0;i<outdegree.size();i++)
        {
            if(outdegree[i]==0)
                q.push(i);
        }
        
        vector<int> res;
       while(q.size()>0)
       {
           int node=q.front();
           //cout<<node;
           q.pop();
           res.push_back(node);
           for(auto it:newgraph[node])
           {
               outdegree[it]--;
               if(outdegree[it]==0)
                   q.push(it);
           }
               
       }
        sort(res.begin(),res.end());
        return res;
        
    }
};