//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
  public:
    long long maxScore(vector<int> &cp, int n, int k) {
      long long sum=0;
      for(auto it:cp)
      sum+=it;
      
      long long res=0;
      
      long long currsum=0;
      int j=0;
      k=n-k;
      while(j<k)
      currsum+=cp[j++];
      
      res=max(res,sum-currsum);
      
      for(int i=k;i<n;i++)
      {
          currsum+=cp[i];
          currsum-=cp[i-k];
          res=max(res,sum-currsum);
      }
      return  res;
      
      
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends