class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        
        string s1even , s1odd;
        string s2even , s2odd;
        
        for(int i = 0;i<s1.size();i++){
            if(i%2 == 0)
                s1even.push_back(s1[i]);
            else
                 s1odd.push_back(s1[i]);
                
        }
         for(int i = 0;i<s1.size();i++){
            if(i%2 == 0)
                s2even.push_back(s2[i]);
            else
                 s2odd.push_back(s2[i]);
                
        }
        sort(s1even.begin() , s1even.end());
        sort(s1odd.begin() , s1odd.end());
        sort(s2even.begin() , s2even.end());
        sort(s2odd.begin() , s2odd.end());
        
        if(s1even+s1odd == s2even+s2odd)return true;
        if(s1odd+s1even == s2odd+s2even)return true;
        
       return false; 
    }
};