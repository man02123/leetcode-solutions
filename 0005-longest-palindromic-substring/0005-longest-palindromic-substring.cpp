class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        
        for(int i=0;i<s.size();i++)
        {
            
               int l = i,r=i;
            while(l>=0 && r<n &&  s[l]==s[r])
            {
                if(r-l+1>ans.size())
                    ans = s.substr(l,r-l+1);
                l--;r++;
            }
            l=i+1;r=i;
            while(l>=0 && r<n &&  s[l]==s[r])
            {
                if(r-l+1>ans.size())
                    ans = s.substr(l,r-l+1);
                l--;r++;
            }
            
            
        }
        return ans;
        
        
    }
//     bool ispal(string &s)
//     {
//         int l = 0,r =s.size()-1;
        
//         while(l<r)
//         {
//             if(s[l] != s[r])
//                 return false;
//             l++;
//             r--;
//         }
//         return true;
//     }
};