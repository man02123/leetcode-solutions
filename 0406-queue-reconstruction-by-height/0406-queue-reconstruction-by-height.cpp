class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0] != b[0])
            return a[0]>b[0]; // decending 
        
        else
            return a[1]<b[1]; // ascending
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        
        sort(p.begin(),p.end(),comp);
        
        vector<vector<int>> res;
        res.push_back(p[0]);
        
        for(int i=1;i<p.size();i++)
        {
            int pos = p[i][1];
            res.insert(res.begin()+pos,p[i]);
        }
        
            return res;
        
        
    }
};