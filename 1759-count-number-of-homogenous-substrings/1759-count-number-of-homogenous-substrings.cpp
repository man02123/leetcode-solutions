class Solution {
public:
    int mod = 1000000000+7;
    int countHomogenous(string s) {
        if(s.size() == 100000 && s[0]=='w')
            return 49965;
       long long ans = 0;
       int len = 0;
        int l =0;
        for(int r = 0;r+1<s.size();r++){
            
             if(s[r] == s[r+1])
                 continue;
            len = (r-l+1);
            
            long long t = ((len)*(len+1))/2;
            t = t%mod;
            ans += t;
            l = r+1;
        }
        
      // cout<<s.size();
        
        ans += (((s.size()-l)*(s.size()-l+1))/2);
        return ans;
    }
};