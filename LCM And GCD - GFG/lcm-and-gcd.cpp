//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<long long> lcmAndGcd(long long a , long long b) {
        vector<long long> res(2);
        
        res[1]=gcd(a,b);
        
        res[0]=(a*b)/res[1];
        return res;
    }
    long long gcd(long long a , long long b)
    {
        if(b==0)
        return a;
        
        return gcd(b,a%b);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends