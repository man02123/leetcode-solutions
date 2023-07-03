class Solution {
public:unordered_map<char,int> mp;
    bool buddyStrings(string s, string g) {
        if(s.size()!=g.size())
            return false;
            
        //unordered_map<char,int> mp;
        for(int i =0;i<s.size();i++)
        {
            mp[s[i]]++;
            
        } 
        
        if(s==g)
        {
          for(auto it:mp)
          {
              if(it.second>=2)
                  return true;
          }
            return false;
        }
            
        int ind1  = -1,ind2 = -1;
        int cnt = 0;
        for(int i =0;i<s.size();i++)
        {
            if(mp.find(g[i])==mp.end())
                return false;
            
           if(s[i] == g[i])
               continue;
            if(s[i]!=g[i] && cnt ==0)
            {
                cnt++;
                ind2 = i;  // next mismatch me g[i]->char ko is ind2 pe hona padega          
            }
            else if(s[i]!=g[i] && cnt==1)
            {
                if(ind2<0 || g[i]!=s[ind2])
                    return false;
            }
            
        }
        
//         if(cnt==0)
//             return false;
        
//         if(cnt%2 == 1)
//             return false;
        
        return true;
    }
};