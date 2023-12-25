class Solution {
public:int memo[101];
    int numDecodings(string s) {
        
    memset(memo,-1,sizeof(memo));
      
        return recur(s,0);
    }
    int recur(string &s ,int ind ){
         if(ind >s.size())return 0;
        
        if(ind == s.size())return 1;
        if(s[ind]=='0')return 0;
        if(memo[ind]!=-1)return memo[ind];
        
        int ans = recur(s,ind+1);
        
            
            int i =ind;
            if(i<s.size() && s[i]=='1')ans+=recur(s,ind+2);
        
            if(i+1<s.size() && s[i]=='2' && (s[i+1]-'0' >=0 && s[i+1]-'0'<=6))ans += recur(s,ind+2);
        
        return memo[ind] = ans ;
    }
};