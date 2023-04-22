//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&nums,int t) {
         int sum=0;
        
        for(auto it:nums)
            sum+=it;
        if((sum+t)%2 !=0 || t+sum<0)
            return 0;
        int x=(sum+t)/2;
        vector<vector<int>> dp(nums.size()+1 ,vector<int> (x+1,-1));
        
       return help(nums,(t+sum)/2,nums.size(),dp);
    }
    int help(vector<int>& nums,int t,int n,vector<vector<int>> &dp)
    {
        if(n==0 && t==0)
            return 1;
        if(n==0)
            return 0;
        if(dp[n][t]!=-1)
            return dp[n][t];
        
      if(t-nums[n-1]>=0)
      {
          return dp[n][t]=help(nums,t-nums[n-1],n-1,dp)+help(nums,t,n-1,dp);
      }
        return dp[n][t]= help(nums,t,n-1,dp);
        
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends