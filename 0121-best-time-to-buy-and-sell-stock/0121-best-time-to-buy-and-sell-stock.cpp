class Solution {
public:
    int maxProfit(vector<int>& p) {
        int minelem=p[0];
        int res=0;
        for(int i=0;i<p.size();i++)
        {
            res=max(res,p[i]-minelem);
            minelem=min(minelem,p[i]);
        }
        return res;
        
    }
};