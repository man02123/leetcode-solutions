//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int x;
  int dp[502][201][3];
    int maxProfit(int k, int n, int a[]) {
        x=n;
        memset(dp,-1,sizeof(dp));
        return recur(a,k,0,true);
    }
    int recur(int a[],int k,int ind,bool canbuy)
    {
        if(k==0 && canbuy==true)
        return 0;
        if(ind>=x)
        return 0;
        if(dp[ind][k][canbuy]!=-1)
        return dp[ind][k][canbuy];
        
        if(canbuy==true && k>0)
        {
            int b = -a[ind]+(recur(a,k-1,ind+1,!canbuy));
            int nb=recur(a,k,ind+1,canbuy);
            return dp[ind][k][canbuy]=max(b,nb);
        }
        int s = a[ind]+(recur(a,k,ind+1,!canbuy));
        int ns = recur(a,k,ind+1,canbuy);
        
        return dp[ind][k][canbuy]=max(s,ns);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends