//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	   // if(n==1)return 0;
	    int res=INT_MAX;
	  
	    int sum=0;
	    for(int i=0;i<n;i++)
	    sum+=arr[i];
	    
	    int dp[n+1][sum+1];
	    
	    for(int i=0;i<n+1;i++)
	     for(int j=0;j<sum+1;j++)
	     {
	         dp[i][j]=0;
	         if(j==0)dp[i][j]=1;
	        
	     }

       
        for(int i=1;i<n+1;i++)
        {
	     for(int j=1;j<sum+1;j++)
	     {
	         
	         if(j-arr[i-1]>=0)
	         {
	             
	             dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
	         
	         }
	         else
	         {
	             dp[i][j]=dp[i-1][j];
	         }
	         
	     }
        }
        vector<int> v;
        for(int i=0;i<=(sum)/2;i++)
    {
        if(dp[n][i]==1)
        {
            v.push_back(i);
            //cout<<i<<" ";
        }
    }
        
        for(int i=0;i<v.size();i++)
        res=min(res,abs(2*v[i]-sum));
        
	     return res;
   
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends