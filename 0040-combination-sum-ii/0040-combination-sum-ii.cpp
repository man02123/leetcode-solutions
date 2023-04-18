class Solution {
public:vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& c, int tar) {
        sort(c.begin(),c.end());
        vector<int> temp;
        recur(c,tar,temp,0);
        return res;
        
    }
    void recur(vector<int>& c,int tar,vector<int> &temp,int ind)
    {
        if(tar==0)
        {
            res.push_back(temp);
            return; 
        }
        if(ind>=c.size())return;
        if(tar<0)return;
        
        for(int i=ind;i<c.size();i++)
        {
            if(i>ind && c[i]==c[i-1] )
                continue;
            temp.push_back(c[i]);
            if(tar-c[i]>=0)
            recur(c,tar-c[i],temp,i+1);
            temp.pop_back();
        }
        
        
     
    }
};