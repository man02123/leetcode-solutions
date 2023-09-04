class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int res=0;
      int j=0;
      
      for(int i=0;i<=s.size()-3;i++)
      {
          while(j<s.size() &&  mp.size()<3)
          {
              mp[s[j++]]++;
          }
          
          if(mp.size()==3)
            res+=1+(s.size()-j);  
          
          
          mp[s[i]]--;
          
       if(mp[s[i]]==0)mp.erase(s[i]);
          
          
      }
        return res;
    
    }
};