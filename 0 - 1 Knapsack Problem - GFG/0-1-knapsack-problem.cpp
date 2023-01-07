//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int dp[1001][1001];
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       memset(dp,-1,sizeof(dp));
       for(int j=0;j<W+1;j++)
        dp[0][j]=0;
        for(int j=0;j<n+1;j++)
        dp[j][0]=0;
        
        for(int i=1;i<n+1;i++)
         for(int j=1;j<W+1;j++)
         {
             if(wt[i-1]<=j)
             dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
             else
             dp[i][j]=dp[i-1][j];
         }
        
       
       
       
      return dp[n][W];
     
      
    }
//  int help(int wt[],int val[],int cap,int item)
//  {
//      if(item==0 || cap==0)
//      return 0;
     
//      if(dp[item][cap]!=-1)return dp[item][cap];
     
     
//      if(cap>=wt[item-1])
//      {
//      int x=val[item-1]+help(wt,val,cap-wt[item-1],item-1);
//      int y=help(wt,val,cap,item-1);
//      return dp[item][cap]=max(x,y);
//      }
     
//      else if(cap<wt[item-1])
//      return dp[item][cap]=help(wt,val,cap,item-1);
         
//  }
    
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends