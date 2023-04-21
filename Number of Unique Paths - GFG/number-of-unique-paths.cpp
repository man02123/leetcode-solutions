//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int m, int n)
    {
    //   int dp[a][b];
    //   for(int i=0;i<a;i++)
    //   {
    //       for(int j=0;j<b;j++)
    //       {
    //           if(i==0 || j==0)
    //           dp[i][j]=1;
    //           else 
    //           dp[i][j]=0;
    //       }
    //   }
       
    
       
    //   for(int i=0;i<a;i++)
    //   {
    //       for(int j=0;j<b;j++)
    //       dp[i][j]=dp[i-1][j]+dp[i][j-1];
    //   }
    //   return dp[a-1][b-1];
     vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        for(int j=0;j<n;j++)
            dp[0][j]=1;
        
        for(int j=0;j<m;j++)
            dp[j][0]=1;
        //dp[0][0]=0;
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends