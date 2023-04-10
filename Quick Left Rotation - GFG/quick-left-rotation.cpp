//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:int l;
	void leftRotate(int arr[], int k, int n) 
	{ k=k%n;
	l=n;
	   rev(arr,0,k-1);
	   rev(arr,k,n-1);
	   rev(arr,0,n-1);
	} 
	void rev(int arr[],int ind1,int ind2)
	{
	    
	   while(ind1<l && ind2>=0 && ind1<=ind2)
	   swap(arr[ind1++],arr[ind2--]);
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
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }


       

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends