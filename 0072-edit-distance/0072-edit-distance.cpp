class Solution {
public:int dp[501][501];
    int minDistance(string w1, string w2) {
        memset(dp,-1,sizeof(dp));
        return recur(w1,w2,0,0);
    }
    int recur(string& w1,string &w2,int ind1,int ind2)
    {
        if(ind1==w1.size() && ind2==w2.size())
            return 0;
        int m=w2.size();
        int n=w1.size();
        if(ind1>=w1.size())
            return abs(m-ind2);
        if(ind2>=w2.size())
            return abs(n-ind1);
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2]; 
        
        
        if(w1[ind1]==w2[ind2])
        {
            return dp[ind1][ind2]=recur(w1,w2,ind1+1,ind2+1);
        }
        else
            return dp[ind1][ind2]=min({1+recur(w1,w2,ind1+1,ind2),1+recur(w1,w2,ind1+1,ind2+1),1+recur(w1,w2,ind1,ind2+1)});
        
        
    }
};