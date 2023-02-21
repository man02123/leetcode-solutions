class Solution {
public:int dp[501];
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,k);
    }
    int solve(vector<int>& arr,int ind, int k)
    {
        if(ind>=arr.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind]; 
            int locmax=0,ans=0;
            int n=arr.size();
            
            for(int s=ind;s<min(ind+k,n);s++)
            {
                    locmax=max(locmax,arr[s]);
                    int tsum=((s+1-ind)*locmax) + solve(arr,s+1,k);
                    ans=max(ans,tsum);
                  
            }
        return dp[ind]=ans;
        
        
    }
};