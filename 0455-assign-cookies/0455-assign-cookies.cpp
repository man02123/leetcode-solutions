class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& cs) {
       sort(g.begin(),g.end());
        sort(cs.begin(),cs.end());
        int count=0;
        
        int child=0,cook=0;
        while(child<g.size() && cook<cs.size())
        {
            if(g[child]<=cs[cook])
            {
                count++;
                cook++;
                child++;
            }
            else if(g[child]>cs[cook])
                  cook++;
            
        }
        return count;
        
    }
};