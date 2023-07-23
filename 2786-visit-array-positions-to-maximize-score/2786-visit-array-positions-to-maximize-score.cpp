#define ll long long 
class Solution {
public:
    ll dp[100001][3];
    int globel ;
    long long maxScore(vector<int>& nums, int x ) {
        int par = 0;
        globel = x;
        memset(dp,-1,sizeof(dp));
        
        if(nums[0]%2 == 1)
            par = 1;
        return nums[0]+solve(nums , 1, par);
    }
     ll  solve(vector<int>& nums, int ind , int par ){
        
        if(ind>= nums.size())
            return 0;
        
        if(dp[ind][par]!=-1)return dp[ind][par];
        ll take = 0;
        ll nottake = 0;
        
        if(par){  // prev odd hai
            
            if(nums[ind]%2 == 1){
                take  = nums[ind] + solve(nums,ind+1,par);
                nottake = solve(nums,ind+1,par);
            }
            else
            {
              take  = nums[ind] + solve(nums,ind+1,!par)-globel;
                nottake = solve(nums,ind+1,par);  
            }
            
        }
        else{      /// even hai
            
           if(nums[ind]%2 == 0){
                take  = nums[ind] + solve(nums,ind+1,par);
                nottake = solve(nums,ind+1,par);
            }
            else
            {
              take  = nums[ind] + solve(nums,ind+1,!par)-globel;
                nottake = solve(nums,ind+1,par);  
            }     
            
        }
        
        return  dp[ind][par] = max(take , nottake);
        
    }
};