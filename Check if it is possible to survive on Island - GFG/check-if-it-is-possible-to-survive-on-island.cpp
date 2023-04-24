//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int surd, int n, int m){
       int sday=surd/7;
       int buy = surd-sday;
       
    //   if(m>=n)
    //   return -1;
       
       int ans;
       if((surd*m)%n==0)
        ans = (surd*m)/n;
       else
       ans= 1+(surd*m)/n;
       
       if(ans<=buy)
       return ans;
       return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends