class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        // if(p.size()==0)
        vector<vector<int>> graph(n);
        vector<int> in(n,0);
        for(auto it:p)
        {
            graph[it[1]].push_back(it[0]);
            in[it[0]]++;
        }
        queue<int> q;
        
        for(int i=0;i<in.size();i++)
            if(in[i]==0)
                q.push(i);
        
        vector<int> res;
        while(q.size()>0)
        {
            int node=q.front();
            q.pop();
            res.push_back(node);
            
            for(auto it:graph[node])
            {
                in[it]--;
                if(in[it]==0)
                    q.push(it);
            }
   
        }
     
            
        
        if(res.size()!=n)
            return {};
        
        return res;
        
    }
};