class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        
        int res=0;
        int j=0;
        int mx=0;
        for(int i=0;i<s.size();i++)
        {
                mp[s[i]]++;
                mx=max(mx,mp[s[i]]);
            
                if((i-j+1)-mx<=k)
                {    
                 res=max(res,i-j+1);
                 continue;
                }
             mp[s[j++]]--;       
        }
        return res;
        
        
    }
};