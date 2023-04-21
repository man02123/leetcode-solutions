//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:;
  vector<int> dp;
    int minimumEnergy(vector<int>& h, int n) {
        dp.resize(h.size()+1,10002);
        
        
        int x=memo(h,0,n);
      return x;
    }
    int memo(vector<int>& h,int ind,int n)
    {
        if(ind==n-1)
        return dp[ind]=0;
        
        if(ind>=n)
        return INT_MAX-10000;
        
        if(dp[ind]!=10002)
        return dp[ind];
        
        int er1=10000,er2=10000;
        if(ind+1<n)
        er1=abs(h[ind+1]-h[ind])+memo(h,ind+1,n);
        
        if(ind+2<n)
        er2=abs(h[ind+2]-h[ind])+memo(h,ind+2,n);
        
        return dp[ind]=min(er1,er2);
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends