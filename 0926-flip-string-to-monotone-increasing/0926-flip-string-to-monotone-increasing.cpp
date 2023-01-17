class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int pones=0;
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
                pones++;
            else
            { 
              res=min(pones,res+1);
            }
        }
        return res;
        
    }
};