//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++


    class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
       vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1,-1));
       
       for(int i=0;i<arr.size()+1;i++)
        for(int j=0;j<sum+1;j++)
        {
            if(j==0 && i==0)dp[i][j]=0;
            
            if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=1;
        }
        for(int i=1;i<arr.size()+1;i++)
        for(int j=1;j<sum+1;j++)
        {
            if(j-arr[i-1]>=0)
            dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }
        
        
     
       
       return dp[arr.size()][sum];
    }
  
    // bool help(vector<int>arr, int tgt,int ind,vector<vector<int>> &dp)
    // {
    //     if(ind<0 || tgt<0)return false;
        
    //     if(ind==0 && tgt==0) return dp[ind][tgt]=true;
    //     if(ind==0 && tgt!=0) return dp[ind][tgt]=false;
        
    //     if(dp[ind][tgt]!=-1)return dp[ind][tgt];
        
    //   // if(tgt<0)return false;
        
    //     //if(tgt==0)return dp[ind][tgt]=true;
        
    //     return dp[ind][tgt]=help(arr,tgt-arr[ind],ind-1,dp) || help(arr,tgt,ind-1,dp);
        
    // }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends