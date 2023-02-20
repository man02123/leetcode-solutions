//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
       vector<int> res;
       vector<int> lis(n+1,1),hash(n+1,0);
      int maxi=1;
      int l=0;
       for(int i=0;i<n;i++)
       {
           hash[i]=i;
           for(int prev=0;prev<i;prev++)
           {
               if(arr[i]>arr[prev] && lis[i]<1+lis[prev])
               {
                   lis[i]=lis[prev]+1;
                   hash[i]=prev;
               }
           }
           if(maxi<lis[i])
           {
               maxi=lis[i];
               l=i;
           }
       }
    
       
      while(hash[l]!=l)
      {
          res.push_back(arr[l]);
          l=hash[l];
      }
      res.push_back(arr[l]);
          reverse(res.begin(),res.end()) ;
       return res;
       
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
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends