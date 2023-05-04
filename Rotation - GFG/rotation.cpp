//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    
	    int  l = 0 ,r = n-1;
	    int ind = -1;
	    while(l<r)
	    {
	        int mid = (l+r)>>1;
	        if(nums[l]<nums[r])
	        {
	            //ind  = l;
	            break;
	        }
	        
	        if(nums[mid] >= nums[l])
	        {
	            //ind = mid;
	            l =mid +1;
	        }
	        else
	        {
	          r = mid;  
	        }
	        
	    }
	    return l;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends