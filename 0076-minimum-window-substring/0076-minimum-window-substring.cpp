class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        int len=INT_MAX;
        string res = "";
        if(s.size()<t.size())
            return "";
        
        if(s.size()==t.size() && s==t)return s;
        
        for(auto it:t)
            mp[it]++;
        
    
        int k =t.size();
        int j = 0,i = 0;;
        int cnt = 0;
        
        for(j=0;j<s.size();j++)
        {
           if(mp[s[j]]>0)
               cnt++;
               mp[s[j]]--;
           
          if(cnt == k)
          {
              while(i<j && mp[s[i]]<0)
              {
                      mp[s[i]]++;
                      i++;
              }
              if(len>j-i+1)
              {
                  res = s.substr(i,j-i+1);
                  len = j-i+1;
              }
              
              mp[s[i++]]++;
              cnt--;
              
             
          }
            
            
        }
       
        if(len == INT_MAX)
            return "";
      
    return res;
 }
    
};