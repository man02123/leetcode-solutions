class Solution {
public:
    bool isAlienSorted(vector<string>& w, string o) {
       int mp[26];
        
        for(int i=0;i<o.size();i++)
            mp[o[i]-'a']=i;
        
        
        for(int i=0;i<w.size()-1;i++)
        {
            
            for(int j=0;j<w[i].size();j++)
            {
                if(j>=w[i+1].size())
                    return false;
                
              if(w[i][j]!=w[i+1][j])
              {
                  int cw=w[i][j]-'a';
                  int nw=w[i+1][j]-'a';
                  
                   if(mp[cw]>mp[nw])
                   return false;
                else break;
            }  
            }
        }
        return true;
        
    }
};