class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(s,0,p,0,false,dp);
    }
    bool solve(string &s,int sind,string &p,int pind,bool star,vector<vector<int>> &dp)
    {
        
       if(sind>s.size() || pind>p.size())
           return false;
        if(sind==s.size() && pind==p.size())
            return dp[sind][pind]=true;
        if(dp[sind][pind]!=-1)
            return dp[sind][pind];
        
        if(p[pind]=='*')
        {
            star=true;
            return dp[sind][pind]=solve(s,sind+1,p,pind,true,dp) || solve(s,sind,p,pind+1,false,dp) ||                            solve(s,sind+1,p,pind+1,false,dp);
        }    
         
       else if(p[pind]=='?')
        {
         return dp[sind][pind]=solve(s,sind+1,p,pind+1,star,dp);
        }
        else if(s[sind]==p[pind])
            return dp[sind][pind]=solve(s,sind+1,p,pind+1,star,dp);
        
    return dp[sind][pind]=false; 
    }
};