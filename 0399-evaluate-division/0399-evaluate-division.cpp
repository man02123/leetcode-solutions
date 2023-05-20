class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        
        map<string,vector<pair<string , double>>> mp;
        
        for(int i =0;i<eq.size();i++)
        {
            double temp = (double)1/val[i];
            mp[eq[i][0]].push_back({eq[i][1],val[i]});
            mp[eq[i][1]].push_back({eq[i][0],temp});
            
        }
        vector<double> res;
        for(int i =0;i<q.size() ;i++)
        {
            string sc = q[i][0];
            string ds = q[i][1];
            map<string,bool> vis;
            res.push_back(dfs(sc,ds,vis,mp));
            
        }
        return res;
    }
    double dfs(string sc,string ds , map<string,bool> &vis,map<string,vector<pair<string,double>>>& mp)
    {
        if(mp.find(sc)==mp.end()   || mp.find(ds) == mp.end())
            return -1.0;
        
        if(sc == ds)
            return 1.0;
        double res =-1.0;  // always keep in mind -1 != -1.0 int this case causing the problem
        
        for(auto it:mp[sc])
        {
            string adjnode = it.first;
            double eW = it.second;
            if(vis[adjnode] == true)
                continue;
            
            vis[adjnode] = true;
            
            res = dfs(adjnode,ds,vis,mp);
            if(res!=-1)
                return res*eW;
            
        }
        return res;
    
    }
};