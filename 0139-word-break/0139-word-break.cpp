class Solution {
public:
    //int dp[301][301];
    unordered_set<string> mp; 
    bool wordBreak(string s, vector<string>& w) {
        for(auto it:w)
            mp.insert(it);
        vector<int> dp(s.size()+1,-1);
        
    return solve(s,0,s.size(),dp);
        
        
    }
    bool solve(string &s,int start,int end,vector<int> &dp)
    {
        if(start>=end)
            return true;
        
        if(dp[start]!=-1)
            return dp[start];
        
        bool flag=false;
        for(int i=start;i<end;i++)
        {
            if(mp.find(s.substr(start,i-start+1))!=mp.end())
            {
                flag=flag || solve(s,i+1,end,dp);  
            }
        }
        return dp[start]= flag;
     
    }
};