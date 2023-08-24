class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        
        int r = 0 , l =0;
        
        while(l<s1.size() && r<s2.size()){
            
            int  myChar = s2[r]-'a';
            
            if( ((s1[l]-'a'+1)%26 == myChar) || ((s1[l]-'a')%26 == myChar) || ((s1[l]-'a')%26 == myChar))
            {
                r++;
                l++;
            }
            else l++;
        }
        //cout<<r;
        if(r==s2.size())return true;
        
     return false;   
    }
};