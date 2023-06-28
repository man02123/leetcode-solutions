class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& pro, int s, int end) {
        vector<vector<pair<int,double>>> pr(n);
        
        for(int i=0;i<e.size();i++)
        {
            pr[e[i][0]].push_back({e[i][1],pro[i]});
            pr[e[i][1]].push_back({e[i][0],pro[i]});
        }
        
        
       vector<double> prob(n);
       priority_queue<pair<double,int>> pq;
        pq.push({1.0,s});
        
        while(!pq.empty())
        {
            int node = pq.top().second;
            double p = pq.top().first;
            pq.pop();
            // if(node  == end)
            //     return p;
            
            for(auto it: pr[node])
            {
                double itpr = it.second;
                int adj = it.first;
                if(p*itpr > prob[adj])
                {
                    prob[adj] = p*itpr;
                    pq.push({p*itpr,adj});
                }
            }
             
            
        }
        return prob[end];
        
    }
};