class Solution {
public:int count;
    int numDistinct(string s, string t) {
        count=0;
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        if(t.size()>s.size())return 0;
        return solve(s,t,0,0,0,dp);
        
    }
     int solve(string &s,string &t,int ind1,int ind2,int len,vector<vector<int>> &dp)
     {
         if(ind2>=t.size() || ind1>=s.size())
         {
             if(t.size()==len)
             return 1;
                 
             return 0;
         }
         
         if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
         
         if(s[ind1]==t[ind2])
         {
            return dp[ind1][ind2]=solve(s,t,ind1+1,ind2+1,len+1,dp)+solve(s,t,ind1+1,ind2,len,dp);
             
         }
         else
         {
             return dp[ind1][ind2]=solve(s,t,ind1+1,ind2,len,dp);
         }  
         
     }
};