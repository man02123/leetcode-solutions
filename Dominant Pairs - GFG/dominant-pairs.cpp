//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        
        int res=0;
        sort(arr.begin(), arr.begin()+n/2);
        // sort(arr.begin(),arr.begin()+n/2);
       
      for(int i=n/2;i<n;i++)
      {
          int temp=5*arr[i];
           
          int pos=(arr.begin()+n/2)-lower_bound(arr.begin(),arr.begin()+n/2,temp);
          
          res+=pos;
      }
       
        return  res;
    } 
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends