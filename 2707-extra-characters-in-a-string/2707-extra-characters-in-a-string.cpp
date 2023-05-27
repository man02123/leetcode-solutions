class Solution {
public:
    unordered_map<string,int> mp;
    
    int minExtraChar(string s, vector<string>& dict) {
        for(auto it:dict)
            mp[it]++;
        vector<int> dp(s.size()+1,-1);
        
        
      return part(s,0,dp) ;
    }
    
    int part(string &s ,int  ind,vector<int> &dp)
    {
        if(ind>s.size())
            return s.size();
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        if(ind==s.size())
            return 0;
        
        int tans = s.size()-ind;
        
        for(int i=ind;i<s.size();i++)
        {
            string x = s.substr(ind,i-ind+1);
            
            
            if(mp.find(x)!=mp.end())
            {
                
               int y = part(s,i+1,dp);
                tans = min(tans,y);
            }
            else
            {
                int y = x.size()+part(s,i+1,dp);
                tans = min(tans,y);
            }
        }
        return dp[ind]=tans;
        
        
    }
};