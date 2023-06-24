class Solution {
public:int dp[21][100001];
    int tallestBillboard(vector<int>& r) {
        int maxi = *max_element(begin(r),end(r));
        int mini = *min_element(begin(r),end(r));
        int sum=0;
        accumulate(begin(r),end(r),sum);
        memset(dp,-1,sizeof(dp));
        
        return solve(r,0,0)/2;
    
      
        return 0;
    }
    int solve(vector<int> &r ,int diff, int ind){
        
        if(ind==r.size()){
            
            if(diff ==0 )
                return 0;
            return INT_MIN;
        }
        if(dp[ind][diff+5000]!=-1)
            return dp[ind][diff+5000];
        
        int s1take = r[ind]+solve(r,diff+r[ind],ind+1);
        int s2take = r[ind]+solve(r,diff-r[ind],ind+1);
        int ntake = solve(r,diff,ind+1);
        
        return dp[ind][diff+5000] = max({s1take,s2take,ntake});
        
        
    }
};