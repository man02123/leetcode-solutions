class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(s,p,0,0,dp);
        
    }
    bool solve(string &s, string &p,int ind1,int ind2,vector<vector<int>> &dp)
    {
        if(ind1>=s.size() && ind2>=p.size())
            return true;
        if(ind1<s.size()  && ind2>=p.size())
            return false;
        
        bool match=false;
        if(ind1<s.size() && (s[ind1]== p[ind2] || p[ind2]=='.'))
            match=true;
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        if(ind2+1<p.size() && p[ind2+1]=='*')
            return dp[ind1][ind2]=solve(s,p,ind1,ind2+2,dp) || (match && solve(s,p,ind1+1,ind2,dp)) ;
        
       else if(match==true)
        {
            return dp[ind1][ind2]=solve(s,p,ind1+1,ind2+1,dp);
        }
                                                               
        return dp[ind1][ind2]=false;   
        
    }
};