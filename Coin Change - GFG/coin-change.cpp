//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    long long int count(int c[], int n, int sum) {
     
     vector<vector<long long int>> dp (n+1,vector<long long int> (sum+1,0));
     
     for(int j =0;j<=sum;j++)
     dp[0][j]= 0;
     
     for(int j =0;j<=n;j++)
     dp[j][0]= 1;
     
     for(int i=1;i<=n;i++)
     {
         for(int j=0;j<=sum;j++)
         {
             if(j-c[i-1]>=0)
             {
                 dp[i][j] += dp[i-1][j] + dp[i][j-c[i-1]];
             }
             else
             dp[i][j] = dp[i-1][j];
         }
     }
     return dp[n][sum];
     
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends