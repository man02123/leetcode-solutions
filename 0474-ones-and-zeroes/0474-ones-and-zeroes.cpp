class Solution {
public:int dp[601][101][101] = {};
    int findMaxForm(vector<string>& s, int m, int n) {
        memset(dp , -1 , sizeof(dp));
        
        //vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
      int x=solve(s,0,m,n); 
        return x;
    }
    int solve(vector<string>& s,int ind,int cz,int cone)
    {
        if(ind>=s.size())return 0;
         
        if(cz<0 || cone<0)return 0;
        
        if(dp[ind][cz][cone]!=-1)return dp[ind][cz][cone];
        int currz=0,currone=0;
        
        for(int i=0;i<s[ind].size();i++)
         (s[ind][i]=='0')?currz++:currone++;

        
        int x=0,y=0;
        
        if(cz-currz>=0 && cone-currone>=0)
        { 
            x=1+solve(s,ind+1,cz-currz,cone-currone);
            y=solve(s,ind+1,cz,cone);
            return dp[ind][cz][cone]=max(x,y);
        }
          return dp[ind][cz][cone]=solve(s,ind+1,cz,cone);    
        
    }
};