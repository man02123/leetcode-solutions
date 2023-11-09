class Solution {
public:int mod = 1000000000+7;
    int numSub(string s) {
        long long ans = 0;
       
        int len =1;
        for(int r = 1;r<s.size();r++){
            
             if(s[r] == s[r-1] && s[r]=='1')
             {
                 len++;
                 ans = (ans+len)%mod;
             } 
            else if(s[r] == '1')
            len = 1,ans = (ans+len)%mod;
            
            
           
            
            
        }
        if(s[0] == '1')
            ans++;
        
        return ans ;
    }
};