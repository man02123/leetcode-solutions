//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int nums[], int n){
        int l = 0,r = n-1;
        int res = INT_MAX;
        while(l<=r)
        {
           int mid = (l+r)>>1;
           if(nums[l]<nums[r])
           {
               res = min(res,nums[l]);
               l = mid+1;
               break;
           }
           
           if(nums[mid]>=nums[l])
           {
               res = min(res,nums[l]);
               l = mid+1;
           }
           else
           {
               res = min(res,nums[mid]);
               r = mid;
           }
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends