//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int n){
        int cnt=0;
        int k=n;
        while(n%10!=n)
        {
           int r=n%10;
           n=n/10;
           if(r!=0 && k%r==0)
           cnt++;
            
        }
         if(k%n==0)
           cnt++;
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends