//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int s, int e) {
      
      //priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ;
      queue<pair<int,int>> pq;
      vector<int> ways(100001 , INT_MAX);
      pq.push({0,s});
      while(pq.size() > 0){
          
          int node = pq.front().second;
          int steps = pq.front().first;
          pq.pop();
          if(node == e)
          return steps;
          
          for(auto it:arr){
              int newnode = (it*node)%100000;
              
              if(1+steps < ways[newnode])
              {
                  ways[newnode]  = 1+steps;
                  pq.push({1+steps , newnode});
              }
          }
   
      }
      return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends