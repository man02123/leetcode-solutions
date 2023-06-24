class Solution {
public:
    int dp[1001][26][26];
    int n;
    int minimizeConcatenatedLength(vector<string>& w) {
        n = w.size();
        memset(dp,-1,sizeof(dp));
        return w[0].size()+solve(w,w[0][0]-'a',w[0].back()-'a',1);
    }
    int solve(vector<string>&w,int start,int end,int ind)
    {
        if(ind>=w.size())
            return 0;
        
        if(dp[ind][start][end]!=-1)
            return dp[ind][start][end];
        
        string x = w[ind];
        int fr = x[0]-'a';
        int lst = x.back()-'a';
        int ast =INT_MAX,alst=INT_MAX;
        
        alst = x.size()+min(alst,solve(w,start,lst,ind+1));
        ast = x.size()+min(ast,solve(w,fr,end,ind+1));
        
        if(fr==end)
        {
            alst = x.size()-1 + min(alst,solve(w,start,lst,ind+1));
            
        }
        if(lst==start)
        {
            ast = x.size()-1 + min(alst,solve(w,fr,end,ind+1));
           // cout<<ast<<endl;
        }
            
        
        
        
        return dp[ind][start][end]=min(ast,alst);
        
    }
};