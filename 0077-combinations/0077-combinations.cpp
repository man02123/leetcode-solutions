class Solution {
public:vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        recur(n,k,1,temp);
        return res;
    }
    void recur(int n,int k,int ind,vector<int> &temp)
    {
        if(temp.size()==k)
        {
            res.push_back(temp);
            return;
        }
        for(int i=ind;i<=n;i++)
        {
            temp.push_back(i);
            recur(n,k,i+1,temp);
            temp.pop_back();
            //recur(n,k,i+1,temp);
        }
    }
};