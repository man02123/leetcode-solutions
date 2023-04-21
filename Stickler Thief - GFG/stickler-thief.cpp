//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> dp;
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        dp.resize(n+1,-1);
        return memo(arr,n-1);
    }
    int memo(int arr[] , int n)
    {
        if(n<0)
        return 0;
        
        if(n==0)
        return arr[0];
        
        if(dp[n]!=-1)
        return dp[n];
        
        int take = arr[n]+memo(arr,n-2);
        int ntake = memo(arr,n-1);
        
        return dp[n] = max(take,ntake);
        
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends