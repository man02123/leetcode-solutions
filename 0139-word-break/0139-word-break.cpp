class Solution {
public:
    int dp[301][301];
    unordered_map<string,int> mp; 
    bool wordBreak(string s, vector<string>& w) {
        for(auto it:w)
            mp[it]=false;
        memset(dp,-1,sizeof(dp));
        
    return solve(s,0,s.size());
        
        
    }
    bool solve(string &s,int start,int end)
    {
        if(start>=end)
            return true;
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        bool flag=false;
        for(int i=start;i<end;i++)
        {
            if(mp.find(s.substr(start,i-start+1))!=mp.end())
            {
                flag=flag || solve(s,i+1,end);  
            }
        }
        return dp[start][end]= flag;
     
    }
};