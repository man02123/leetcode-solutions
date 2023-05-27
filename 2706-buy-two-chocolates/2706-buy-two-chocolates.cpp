class Solution {
public:
    int buyChoco(vector<int>& p, int m) {
        sort (p.begin(),p.end());
        int mleft = m;
            int cnd = 0;
        
            for(int i=0;i<p.size();i++)  
            {
                if(p[i]<=mleft)
                {
                    cnd++;
                    mleft-=p[i];
                }
                
                if(cnd==2)
                    break;
                
            }
        if(cnd ==2)
            return mleft;
        
        
        return m;
        
        
    }
};