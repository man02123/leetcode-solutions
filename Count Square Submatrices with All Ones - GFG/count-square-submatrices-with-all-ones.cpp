//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSquares(int n, int m, vector<vector<int>> &mat) {
        vector<vector<int>> dp(n,vector<int> (m,0));
        for(int i = 0;i<n;i++)
         dp[i][0] = mat[i][0];
         for(int i = 0;i<m;i++)
         dp[0][i] = mat[0][i];
         
         for(int i = 1;i<n;i++)
         {
             for(int j=1;j<m;j++)
             {
                 if(mat[i][j] == 1 )
                 dp[i][j] = 1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
             }
         }
         int sum = 0;
         
         for(auto i = 0;i<n;i++)
         {
             for(int j = 0;j<m;j++)
             sum+=dp[i][j];
         }
             return sum;
         
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.countSquares(N, M, matrix) << endl;
    }
    return 0;
}
// } Driver Code Ends