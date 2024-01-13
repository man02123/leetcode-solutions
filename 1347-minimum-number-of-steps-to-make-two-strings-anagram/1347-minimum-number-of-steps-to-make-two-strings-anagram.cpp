class Solution {
public:
    int minSteps(string s, string t) {
      
        vector<int> v(26,0);
        int res=0;
        for(int i=0;i<s.size();i++)
            v[s[i]-'a']++;
        for(int i=0;i<t.size();i++)
        {
            if(v[t[i]-'a']>0)v[t[i]-'a']--;
    
        }
       for(auto it:v)
           if(it>0)res+=it;
        
        return res;
    }
};