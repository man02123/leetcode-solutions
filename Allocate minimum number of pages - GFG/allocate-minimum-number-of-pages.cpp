//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        if(m>n)
        return -1;
       int l=INT_MIN,r=0;
       for(int i=0;i<n;i++)
        {
            l=max(l,a[i]);
            r+=a[i];
        }
        while(l<r)
        {
            int mid=(l+r)/2;
            
            if(check(a,n,mid,m)==true)
                r=mid;
            else
            l=mid+1;
        }
        return l;
        
      
    }
    bool  check(int a[],int n,int pages,int div)
    {
        int need=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum>pages)
            {
                need++;
                sum=a[i];
            }
        }
        if(need<=div)
        return true;
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends