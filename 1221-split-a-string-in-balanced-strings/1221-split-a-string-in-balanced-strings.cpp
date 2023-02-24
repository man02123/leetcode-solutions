class Solution {
public:
    int balancedStringSplit(string s) {
        int lc=0;
        int rc=0;
        int i=0,cnt=0;
        
        while(i<s.size())
        {
            if(s[i]=='L')
                lc++;
            else if(s[i]=='R')
                rc++;
            
            if(lc==rc)
                cnt++,lc=0,rc=0;
            i++;
            
        }
        return cnt;
        
    }
};