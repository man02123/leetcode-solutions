class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        
        vector<int> s,e;
        for(auto it:f){
            s.push_back(it[0]);
            e.push_back(it[1]);
        }
        sort(begin(s),end(s));
        sort(begin(e),end(e));
        
        vector<int> res;
        
        for(int i =0;i<p.size();i++){
           
           int lb = upper_bound(begin(s),end(s),p[i])-begin(s);
            int ub = lower_bound(begin(e),end(e),p[i])-begin(e);
            
            res.push_back(lb-ub);
        }
        return res;
    }
};

















