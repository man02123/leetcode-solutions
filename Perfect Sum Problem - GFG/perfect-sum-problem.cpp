//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    static int mod=1000000007;
	  vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
      for(int i=0;i<n+1;i++)
       for(int j=0;j<sum+1;j++)
       {
           if(i==0)dp[i][j]=0;
           if(j==0)dp[i][j]=1;
       }
       
       for(int i=1;i<n+1;i++)
       for(int j=0;j<sum+1;j++)
       {
           if(j-arr[i-1]>=0)
           dp[i][j]=dp[i-1][j-arr[i-1]]%mod +dp[i-1][j]%mod;
           else
           dp[i][j]=dp[i-1][j]%mod;
           
       }
      
      
      
      
        return dp[n][sum]%mod;
	}
// 	int help(int arr[],int sum,int ind,vector<vector<int>> &dp)
// 	{
	        
// 	    if(ind<0 || sum<0)return 0;
	    
// 	    if(ind==1)
// 	    {
// 	        if(arr[ind-1]-sum==0)return 2;
// 	    }
// 	    if(sum==0)return dp[ind][sum]=1;
	  
	    
// 	    if(dp[ind][sum]!=-1)return dp[ind][sum];
	    
// 	   int x= help(arr,sum-arr[ind-1],ind-1,dp);
// 	    int y=help(arr,sum,ind-1,dp);
//         return dp[ind][sum]=(x+y);
// 	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends