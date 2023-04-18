class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& cand, int tar) {
    vector<int> temp;
        recur(cand,tar,temp,0);
        return res;
        
    }
    void recur(vector<int>& cand,int tar,vector<int> &temp,int ind)
    {
        if(tar==0)
        {
            res.push_back(temp);
            return ;
        }
        
        
        if(tar>0)
        {
        for(int i=ind;i<cand.size();i++)
        {
           temp.push_back(cand[i]);
           recur(cand,tar-cand[i],temp,i);
            temp.pop_back();
            
        }
        }
        
        
        
    }
};