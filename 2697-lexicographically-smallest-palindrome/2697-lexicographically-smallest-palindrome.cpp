class Solution {
public:
    string makeSmallestPalindrome(string s) {
        
        int i = 0,r = s.size()-1;
        while(i<r)
        {
            if(s[i]!=s[r])
            {
                if(s[i]>s[r])
                    s[i] = s[r];
                else
                    s[r] = s[i];
            }
            i++;
            r--;
     
        }
        
       return s; 
    }
};