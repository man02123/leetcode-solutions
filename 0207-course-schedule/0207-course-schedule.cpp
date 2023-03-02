class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& g) {
        
        vector<int> indegree(n,0);
        vector<vector<int>> graph(n);
        
       for(auto it:g)
       {
           graph[it[1]].push_back(it[0]);
           indegree[it[0]]++;
       }
        
        queue<int> q;
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);
            
        int count=0;
        while(q.size()>0)
        {
          int node=q.front();
            q.pop();
            count++;
          
            for(auto it:graph[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
            
            
        }
        return (count==n)?1:0;
            
        
    }
};