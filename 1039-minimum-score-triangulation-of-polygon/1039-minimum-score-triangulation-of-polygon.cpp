class Solution {
public:int dp[501][502];
    int minScoreTriangulation(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
     return mcm(v,1,v.size()-1);   
    }
    int mcm(vector<int>& v,int i,int j)
    {
        if(j<=i)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int p=i;p<j;p++)
        {
            int tempans=v[i-1]*v[p]*v[j]+mcm(v,i,p)+mcm(v,p+1,j);
            ans=min(tempans,ans);
        }
        return dp[i][j]=ans;
        
    }
};