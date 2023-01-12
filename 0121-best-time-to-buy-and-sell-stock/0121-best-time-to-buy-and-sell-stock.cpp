class Solution {
public:
    int maxProfit(vector<int>& p) {
        int minelem=p[0];
        int res=INT_MIN;
        for(int i=1;i<p.size();i++)
        {
            res=max(p[i]-minelem,res);
            minelem=min(minelem,p[i]);
        }
        if(res<0)return 0;
        else
            return res;
    }
};