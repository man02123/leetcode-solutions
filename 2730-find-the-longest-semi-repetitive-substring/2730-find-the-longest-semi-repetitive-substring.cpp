class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
       // unordered_map<string,int> mp;
        int ans = 1;
        
        for(int i = 0;i<s.size();i++)
        {
            
            for(int j = 0;j<=i;j++){
                int t =1;
                for(int k =j+1;k<=i;k++)
                {
                   if(s[k] == s[k-1])
                       t--;
                    if(t>=0)
                    {
                        ans = max(ans,k-j+1);
                    }
                }
               
            }
        }
        
        
        return ans;
        
    }
};
//"0"
   // ans =1