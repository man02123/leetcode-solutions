//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
       return mcm(arr,1,N-1,dp);
       
    }
    int mcm(int arr[],int start,int end,vector<vector<int>> &dp)
    {
        if(start>end)
        return INT_MAX;
        if(start==end)
        return 0;
        if(dp[start][end]!=-1)
        return dp[start][end];
        
        int tans = INT_MAX-1;
        
        for(int part = start; part<=end-1;part++)
        {
          int ans = arr[start-1]*arr[part]*arr[end]+mcm(arr,start,part,dp)+mcm(arr,part+1,end,dp);
          tans = min(tans,ans);
        }
        
        return dp[start][end]=tans;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends